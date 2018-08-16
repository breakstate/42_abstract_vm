#ifndef FACTORY_H
# define FACTORY_H
# include "IOperand.hpp"
# include "Type.hpp"

class IOperand;

class Factory {
public:

	Factory( void );
	~Factory( void );
	IOperand const * createOperand( eOperandType type, std::string const & value ) const;

protected:
	
private:

	typedef IOperand const *(Factory::*f)(std::string const &) const;
	static f funcs[];

	IOperand const * createInt8( std::string const & value ) const;
	IOperand const * createInt16( std::string const & value ) const;
	IOperand const * createInt32( std::string const & value ) const;
	IOperand const * createFloat( std::string const & value ) const;
	IOperand const * createDouble( std::string const & value ) const;
};

#endif