#include "../hdr/AVM.hpp"

AVM::AVM( void ) {
	this->_instructionSet[0] = "push";
	this->_instructionSet[1] = "pop";
	this->_instructionSet[2] ="dump";
	this->_instructionSet[3] = "assert";
	this->_instructionSet[4] = "add";
	this->_instructionSet[5] = "sub";
	this->_instructionSet[6] = "mul";
	this->_instructionSet[7] = "div";
	this->_instructionSet[8] = "mod";
	this->_instructionSet[9] = "print";
	this->_instructionSet[10] = "exit";
	this->_instructionSet[11] = ";;";
	this->_typeSet[0] = "int8";
	this->_typeSet[1] = "int16";
	this->_typeSet[2] = "int32";
	this->_typeSet[3] = "float";
	this->_typeSet[4] = "double";
	this->_lexer = new Lexer( this->_instructionSet, this->_typeSet );
	this->_parser = new Parser();
}

AVM::AVM( const AVM & srcObj ) {
	this->operator=(srcObj);
}

AVM & AVM::operator=( AVM const & rhs ) {
	this->_lexer = rhs._lexer;
	this->_parser = rhs._parser;
	this->_instructionSet = rhs._instructionSet;
	this->_typeSet = rhs._typeSet;
	this->_program = rhs._program;
	return(*this);
}

AVM::~AVM( void ) {
	delete this->_lexer;
	delete this->_parser;
}

void	AVM::run( int argc, char **argv ) {
	this->_lexer->read( argc, argv );
	this->_program = this->_lexer->getProgram();
	this->_parser->execute( _program );
}