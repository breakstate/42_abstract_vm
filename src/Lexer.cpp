#include "../hdr/Lexer.hpp"

Lexer::Lexer( void ) {
}

Lexer::Lexer( std::array<std::string, 12> _instructionSet, std::array<std::string, 5> _typeSet ) {
	this->_delimiter = " ";
	this->_comment = ";";
	this->_instructionSet = _instructionSet;
	this->_typeSet = _typeSet;
}

Lexer::Lexer( const Lexer & srcObj ) {
	this->operator=(srcObj);
}

Lexer & Lexer::operator=( Lexer const & rhs ) {
this->_program = rhs._program ;
this->_delimiter = rhs._delimiter;
this->_comment = rhs._comment;
this->_instructionSet = rhs._instructionSet;
this->_typeSet = rhs._typeSet;
this->_lexicalErrors = rhs._lexicalErrors;
return (*this);
}

Lexer::~Lexer( void ) {
}

void	Lexer::_isValidFile( std::string filename ) {
	struct stat s;

	if( stat(filename.c_str(),&s) == 0){
		if (!(s.st_mode & S_IFREG ))
			throw AVMException("AVMException::file: file is not valid");
	}
	else
		throw AVMException("AVMException::file: file does not exist");
}

void	Lexer::read( int argc, char** argv ) {
	size_t		pos = 0;
	int			smallBreak = 0;
	int			bigBreak = 0;
	int			i = -1;
	int			lineCount = 0;
	std::string	line;

	if (argc == 2) {
		this->_isValidFile( argv[1] );
		std::string token;
		std::ifstream infile( argv[1] );
		while (bigBreak == 0 && getline( infile, line )) // read from file
			this->_getLines( line, pos, smallBreak, bigBreak, i, lineCount );
	}
	else if (argc == 1)
		while (bigBreak == 0 && getline(std::cin, line)) // read from std::in
			this->_getLines( line, pos, smallBreak, bigBreak, i, lineCount );
	else
		throw AVMException("AVMException::arguments: too many command line arguments, expected 1");
	this->_lexicalValidation();
}

void	Lexer::_getLines( std::string & line, size_t & pos, int & smallBreak, int & bigBreak, int & i, int & lineCount ) {
	i++;
	lineCount++;
	pos = 0;
	smallBreak = 0;

	if ((pos = line.find(this->_comment)) != std::string::npos)
		if (line[pos + 1] != ';'){
			line = line.substr(0, pos);
		}
	pos = 0;
	this->_getTokens(line, pos, smallBreak, i, lineCount);
	if (!(this->_program.empty()))
		if (this->_program[i].lineContents[0] == ";;"){
			bigBreak = 1;
		}
}

void	Lexer::_getTokens( std::string & line, size_t & pos, int & smallBreak, int & i, int & lineCount ) {
	std::vector<std::string> *strVec;
	strVec = new std::vector<std::string>;

	while (!smallBreak){
		pos = line.find(this->_delimiter);
		if (line.substr(0, pos).length() > 0){
			strVec->push_back(line.substr(0, pos));
		}
		line.erase(0, pos + 1);
		if (pos == std::string::npos){
			smallBreak = 1;
		}
	}
	if (!strVec->empty()){
		program *newLine = new program;
		newLine->lineContents = *strVec;
		newLine->lineNumber = lineCount;
		this->_program.push_back(*newLine);
		delete newLine;
	}
	else{
		i--;
	}
	delete strVec;
}

void	Lexer::debugPrintProg( void ) {
	std::cout << std::endl << "DEBUG DUMP:" << std::endl;
	int j = 0;
	for (int i = 0; i < static_cast<int>(this->_program.size()); i++){
		for (j = 0; j < static_cast<int>(this->_program[i].lineContents.size()); j++){	
			std::cout << this->_program[i].lineContents[j] << " " << i << ":" << j << std::endl;
		}
	}
}

std::vector<program> Lexer::getProgram( void ) {
	return this->_program;
}

void	Lexer::_lexicalValidation( void ) {
	for (int i = 0; i < static_cast<int>(this->_program.size()); i++){
		this->_isValidInstruction(this->_program[i]);
	}
	if (this->_lexicalErrors.length() > 0)
		throw AVMException("** AVMExecption::Lexer: **\n" + _lexicalErrors);
}

void	Lexer::_isValidInstruction( program & line){
	for (int i = 0; i < static_cast<int>(this->_instructionSet.size()); i++){
		if (line.lineContents[0].compare(this->_instructionSet[i]) == 0){
			if ((line.lineContents[0].compare("push") == 0) ||
			   (line.lineContents[0].compare("assert") == 0)){
				line.instruction = line.lineContents[0];
				this->_isValidType( line );
				return;
			   }
			else
				line.instruction = line.lineContents[0];
				return;
		}
	}
	this->_lexicalErrors += "Line " + std::to_string(line.lineNumber) + ": Invalid instruction: " + ("\"" + line.lineContents[0] + "\"\n");
}

void	Lexer::_isValidType( program & line ){
	size_t pos;
	std::string newType;

	if (line.lineContents.size() == 2){
		if ((pos = line.lineContents[1].find("(")) != std::string::npos){
			newType = line.lineContents[1].substr(0, pos);
			line.lineContents[1].erase(0, pos); // erasing rest of line
			line.value = line.lineContents[1];
		}
		else{
			this->_lexicalErrors += "Line " + std::to_string(line.lineNumber) + ": Invalid type/value, expected int8, int16, int32, float or double then value in braces: " + ("\"" + line.lineContents[1] + "\"\n");
			return;
		}
		for (int i = 0; i < static_cast<int>(this->_typeSet.size()); i++){
			if (newType.compare(this->_typeSet[i]) == 0){
				line.type = newType;
				this->_isValidValue( line );
				return;
			}
		}
		this->_lexicalErrors += "Line " + std::to_string(line.lineNumber) + ": Invalid type: " + ("\"" + newType + "\"\n");
	}
	else
		this->_lexicalErrors += "Line " + std::to_string(line.lineNumber) + ": Wrong number of values, expected 1 for instruction " + ("\"" + line.lineContents[0] + "\"\n");
}

void	Lexer::_isValidValue( program & line ){
	size_t startPos;
	size_t endPos;
	std::string newValue;

	if ((startPos = line.lineContents[1].find_first_of("(")) != std::string::npos){
		if ((endPos = line.lineContents[1].find_last_of(")")) != std::string::npos){
			newValue = line.lineContents[1].substr(startPos + 1, (endPos - startPos - 1)); // problem here? make sure value exists
			if (newValue.length() < 1)
				this->_lexicalErrors += "Line " + std::to_string(line.lineNumber) + ": No value found: " + ("\"" + line.lineContents[1] + "\"\n");
			else{
				line.value = newValue;
				this->_isValue(line);
			}
		}
		else
			this->_lexicalErrors += "Line " + std::to_string(line.lineNumber) + ": Invalid value, no closing brace: " + ("\"" + line.lineContents[1] + "\"\n");
	}
	else
		this->_lexicalErrors += "Line " + std::to_string(line.lineNumber) + ": Invalid value, no opening brace: " + ("\"" + line.lineContents[1] + "\"\n");
}

void	Lexer::_isValue( program & line ){
	char* p;
	strtold(line.value.c_str(), &p);
	if ((*p)) 
		this->_lexicalErrors += "Line " + std::to_string(line.lineNumber) + ": Invalid value \"" + line.value + "\" in " + ("\"" + line.lineContents[1] + "\", expected (numericalValue) in single brackets\n");
}// note, Parser can easily deal with this