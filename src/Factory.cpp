#include "../hdr/Factory.hpp"
#include "../hdr/IOperand.hpp"

Factory::f Factory::funcs[] = {&Factory::createInt8, &Factory::createInt16, &Factory::createInt32, &Factory::createFloat, &Factory::createDouble};

Factory::Factory( void ) {
}

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const {
	return (this->*funcs[type])(value);
}

IOperand const * Factory::createInt8( std::string const & value ) const {
	IOperand const *newInt8;
	newInt8 = new Operand <int8_t> ( std::stoi(value) , INT8, 0, this);
	return (newInt8);
}

IOperand const * Factory::createInt16( std::string const & value ) const {
	IOperand const *newInt16;
	newInt16 = new Operand <int16_t> ( std::stoi(value) , INT16, 0, this);
	return (newInt16);
}

IOperand const * Factory::createInt32( std::string const & value ) const {
	IOperand const *newInt32;
	newInt32 = new Operand <int32_t> ( std::stoi(value), INT32, 0, this);
	return (newInt32);
}

IOperand const * Factory::createFloat( std::string const & value ) const {
	IOperand const *newFloat;
	newFloat = new Operand <float> ( std::stof(value), FLOAT, 6, this);
	return (newFloat);
}

IOperand const * Factory::createDouble( std::string const & value ) const {
	IOperand const *newDouble;
	newDouble = new Operand <double> ( std::stod(value), DOUBLE, 15, this);
	return (newDouble);
}

Factory::~Factory( void ) {	
}