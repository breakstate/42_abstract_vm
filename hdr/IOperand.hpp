#ifndef IOPERAND_H
# define IOPERAND_H
# include <iostream>
# include <string>
# include "Type.hpp"

class IOperand {

public:
    virtual int getPrecision( void ) const = 0; // Precision of the type of the instance
    virtual eOperandType getType( void ) const = 0; // Type of the instance

    virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
    virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
    virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
    virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
    virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo

    virtual std::string const & toString( void ) const = 0; // String representation of the instance
    
    virtual ~IOperand( void ) {}
};

template <class T> 
class Operator : public IOperand {

public:
// constructor takes precision, type, value, string
    T    value;
    std::string type;
    int     precision;

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