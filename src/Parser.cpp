#include "../hdr/Parser.hpp"

Parser::Parser( void ) {
}

Parser::Parser( const Parser & srcObj ) {
	this->operator=(srcObj);
}

Parser & Parser::operator=( Parser const & rhs ) {
	this->_stackObject = rhs._stackObject;
	this->_parseErrors = rhs._parseErrors;
	return (*this);
}

Parser::~Parser( void ) {
}

void	Parser::execute( std::vector<program>  program) {
	for (unsigned int i = 0; i < program.size(); i++){
		if (program[i].lineContents[0].compare("push") == 0){
			inputOverflow( interpretType(program[i].type), program[i].value);
			this->_stackObject.push( this->interpretType(program[i].type), program[i].value );
		}
		else if (program[i].lineContents[0].compare("pop") == 0)
			this->_stackObject.pop();
		else if (program[i].lineContents[0].compare("dump") == 0)
			this->_stackObject.dump();
		else if (program[i].lineContents[0].compare("assert") == 0){
			inputOverflow( interpretType(program[i].type), program[i].value);
			this->_stackObject.assert( this->interpretType(program[i].type), program[i].value );
		}
		else if (program[i].lineContents[0].compare("add") == 0)
			this->_stackObject.add();
		else if (program[i].lineContents[0].compare("sub") == 0)
			this->_stackObject.sub();
		else if (program[i].lineContents[0].compare("mul") == 0)
			this->_stackObject.mul();
		else if (program[i].lineContents[0].compare("div") == 0)
			this->_stackObject.div();
		else if (program[i].lineContents[0].compare("mod") == 0)
			this->_stackObject.mod();
		else if (program[i].lineContents[0].compare("print") == 0)
			this->_stackObject.print();
		else if (program[i].lineContents[0].compare("exit") == 0)
			return;
		else if (program[i].lineContents[0].compare(";;") == 0){
			;
		}
	}
	throw AVMException("AVMException::exit: No exit instruction found"); 
}

void	Parser::inputOverflow( eOperandType type, std::string value ) {
	char* p;
	long double result = strtold(value.c_str(), &p);
	if ((*p)) 
		throw AVMException("AVMXecption::Parser: failed to convert value");
	switch (type){
	case INT8:
		if (result > std::numeric_limits<int8_t>::max() || result < std::numeric_limits<int8_t>::min())
			throw AVMException("AVMException::INT8: over/underflow detected");
		break;
	case INT16:
		if (result > std::numeric_limits<int16_t>::max() || result < std::numeric_limits<int16_t>::min())
			throw AVMException("AVMException::INT16: over/underflow detected");
		break;
	case INT32:
		if (result > std::numeric_limits<int32_t>::max() || result < std::numeric_limits<int32_t>::min())
			throw AVMException("AVMException::INT32: over/underflow detected");
		break;
	case FLOAT:
		if (result > std::numeric_limits<float_t>::max() || result < (-std::numeric_limits<float_t>::max()))
			throw AVMException("AVMException::FLOAT: over/underflow detected parser"); // debug WHY IN THE HELL IS THIS THROWING?
		break;
	case DOUBLE:
		if (result > std::numeric_limits<double_t>::max() || result < (-std::numeric_limits<double_t>::max()))
			throw AVMException("AVMException::DOUBLE: over/underflow detected");
		break;
	}
}

eOperandType Parser::interpretType( std::string value ) {
	if (value == "int8")
		return INT8;
	else if (value == "int16")
		return INT16;
	else if (value == "int32")
		return INT32;
	else if (value == "float")
		return FLOAT;
	else
		return DOUBLE;
}