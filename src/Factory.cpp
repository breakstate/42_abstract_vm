#include "../hdr/Factory.hpp"
#include "../hdr/Type.hpp"

Factory::Factory( void ) {
//	this->funcPtr = Factory::createInt16;
}

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const {
	// don't think this will work, treat as placeholder
	switch( type ){
	case Int8:
		return (this->createInt8( value ));
		break;
	case Int16:
		return (this->createInt16( value ));
		break;
	case Int32:
		return (this->createInt32( value ));
		break;
	case Float:
		return (this->createFloat( value ));
		break;
	case Double:
		return (this->createDouble( value ));
		break;
	};
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