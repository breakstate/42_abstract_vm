#ifndef FACTORY_H
# define FACTORY_H
# include "IOperand.hpp"
# include "Type.hpp"

class Factory {

public:
	Factory( void );
	IOperand const * createOperand( eOperandType type, std::string const & value ) const;
	~Factory( void );	

protected:
	
private:
	//const IOperand (Factory::*funcPtr)(std::string const & value) const; //= { createInt8, createInt16, createInt32, createFloat, createDouble};
	//funcPtr[0] = createInt8;


	IOperand const * createInt8( std::string const & value ) const;
	IOperand const * createInt16( std::string const & value ) const;
	IOperand const * createInt32( std::string const & value ) const;
	IOperand const * createFloat( std::string const & value ) const;
	IOperand const * createDouble( std::string const & value ) const;

};

#endif