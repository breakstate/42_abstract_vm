#ifndef IOPERAND_H
# define IOPERAND_H
# include <iostream>
# include <string>
# include "Type.hpp"
# include "stdlib.h"

class IOperand {

public:
    //virtual int getPrecision( void ) const = 0; // Precision of the type of the instance
    //virtual eOperandType getType( void ) const = 0; // Type of the instance

    virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
    virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
    //virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
    //virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
    //virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo

    virtual std::string const & toString( void ) const = 0; // String representation of the instance
    
    //virtual ~IOperand( void ) {}
};

template <class T> 
class Operator : public IOperand {

public:
    // coplien stuff
    Operator( T value, std::string type, int precision ) : value(value), type(type), precision(precision) {};
    ~Operator( void ) {};
    //Operator( const Operator & srcObj );
    //Operator & operator=( Operator const & srcObj );  
    // member functions 

// constructor takes precision, type, value, string
    T    value;
    std::string type;
    int     precision;

    std::string const & toString( void ) const {
		std::string *ret = new std::string(std::to_string(this->value));
        return (*ret);
    }
    IOperand const * operator+( IOperand const & rhs ) const {
        Operator <T> *retObj;
        retObj = new Operator(this->value + std::stoi(rhs.toString()) , "int", 0);
        std::cout << retObj->value << std::endl;
        return (retObj);
    }
    IOperand const * operator-( IOperand const & rhs ) const {
        Operator <T> *retObj;
        retObj = new Operator(this->value - std::stoi(rhs.toString()), "int", 0);
        std::cout << retObj->value << std::endl;
        return (retObj);
    }
    IOperand const * operator*( IOperand const & rhs ) const {
        Operator <T> *retObj;
        retObj = new Operator(this->value * std::stoi(rhs.toString()), "int", 0);
        std::cout << retObj->value << std::endl;
        return (retObj);
    }
    IOperand const * operator/( IOperand const & rhs ) const {
        Operator <T> *retObj;
        retObj = new Operator(this->value - std::stoi(rhs.toString()), "int", 0);
        std::cout << retObj->value << std::endl;
        return (retObj);
    }
    IOperand const * operator%( IOperand const & rhs ) const {
        Operator <T> *retObj;
        retObj = new Operator(this->value - std::stoi(rhs.toString()), "int", 0);
        std::cout << retObj->value << std::endl;
        return (retObj);
    }

protected:

private:

};

#endif
