#include "../hdr/Factory.hpp"
#include "../hdr/Type.hpp"

Factory::Factory( void ) {
//	this->funcPtr = Factory::createInt16;
}

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const {
	// call appropriate member function
	// using array of function pointers 
	// indexed with the enum
	// return constant pointer to IOperand obect
}

IOperand const * Factory::createInt8( std::string const & value ) const {
	
}

IOperand const * Factory::createInt16( std::string const & value ) const {

}

IOperand const * Factory::createInt32( std::string const & value ) const {

}

IOperand const * Factory::createFloat( std::string const & value ) const {

}

IOperand const * Factory::createDouble( std::string const & value ) const {

}

Factory::~Factory( void ) {
	
}