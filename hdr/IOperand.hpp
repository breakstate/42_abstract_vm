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

    //virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
    //virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
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
		std :: string *ret = new std::string(std::to_string(this->value));
        return (*ret);
    }
    /*IOperand const * operator+( IOperand const & rhs ) const {
        Operator *test;//(0, "int", 0);
        test = new Operator(0, "int", 0);
        test->value = this->value + std::stoi(rhs.toString());
        std::cout << test->value << std::endl;
        return (test);
    }*/
    /*std::string const & toString( void ) const {
        std::string strVal = std::to_string(this->value);
        std::cout << strVal << std::endl;
        return ("50");
    }*/



protected:

private:

};
/*
class Int8 : public IOperand {

public:
    char    value;
    std::string type;
    int     precision;

protected:

private:

};

class Int16 : public IOperand {

public:
    short value;
    std::string type;
    int     precision;

protected:

private:

};

class Int32 : public IOperand {

public:
    int value;
    std::string type;
    int     precision;

protected:

private:

};

class Float : public IOperand {

public:
    float value;
    std::string type;
    int     precision;

protected:

private:

};

class Double : public IOperand {

public:
    double value;
    std::string type;
    int     precision;

protected:

private:

};
*/
#endif
