#ifndef IOPERAND_H
# define IOPERAND_H

# include <iostream>
# include <iomanip>
# include <sstream>
# include <float.h>
# include <string>
# include <math.h>
# include <stdlib.h>
# include <limits>

# include "Type.hpp"
# include "Factory.hpp"
# include "AVMException.hpp"

class Factory;

class IOperand {

public:
    virtual int getPrecision( void ) const = 0;
    virtual eOperandType getType( void ) const = 0;

    virtual IOperand const * operator+( IOperand const & rhs ) const = 0;
    virtual IOperand const * operator-( IOperand const & rhs ) const = 0;
    virtual IOperand const * operator*( IOperand const & rhs ) const = 0;
    virtual IOperand const * operator/( IOperand const & rhs ) const = 0;
    virtual IOperand const * operator%( IOperand const & rhs ) const = 0;

    virtual std::string const & toString( void ) const = 0;
    
    virtual ~IOperand( void ) {}
};

template <class T> 
class Operand : public IOperand {

public:
    Operand( void ) {}
    ~Operand( void ) {}
    
    Operand( const Operand & srcObj ) {
        this->operator=(srcObj);
    }

    Operand & operator=( Operand const & srcObj ) {
    this->value = srcObj.value;
    this->type = srcObj.type;
    this->precision = srcObj.precision;
    this->myFactory = srcObj.myFactory;
    this->result = srcObj.result;
    return (*this);
    }

    Operand( T value, eOperandType type, int precision, const Factory *factory ) : value(value), type(type), precision(precision), myFactory(factory) {}

    T   value;
    eOperandType type;
    int     precision;
    const Factory *myFactory;
    long double result;

    eOperandType biggerType( IOperand const & rhs ) const {
        return (this->type >= rhs.getType() ? this->type : rhs.getType());
    }

    std::string const & toString( void ) const {
        std::string *ret;
            std::ostringstream out;
            if (this->getType() == 3 || this->getType() == 4){
                out << std::fixed << std::setprecision(2) << this->value;
	            ret = new std::string(out.str());
            }
            else
                ret = new std::string(std::to_string(this->value));
        return (*ret);
    }

    int getPrecision( void ) const {
        return (this->precision);
    }

    int getPrecision( eOperandType type ) const {
        switch (type){
            case INT8:
                return (0);
            case INT16:
                return (0);
            case INT32:
                return (0);
            case FLOAT:
                return (6);
            case DOUBLE:
                return (15);
        }
    }

    eOperandType getType( void ) const {
        return (type);
    }

    IOperand const * operator+( IOperand const & rhs ) const {
        long double result = this->value + std::stod(rhs.toString());
        return this->myFactory->createOperand(this->biggerType( rhs ), std::to_string(result) );
    }
    
    IOperand const * operator-( IOperand const & rhs ) const {
        long double result = this->value - std::stod(rhs.toString());
        return this->myFactory->createOperand(this->biggerType( rhs ), std::to_string(result) );
    }

    IOperand const * operator*( IOperand const & rhs ) const {
        long double result = this->value * std::stod(rhs.toString());
        isOverflow(this->biggerType( rhs ), result);
        return this->myFactory->createOperand(this->biggerType( rhs ), std::to_string(result) );
    }

    IOperand const * operator/( IOperand const & rhs ) const {
        long double result = this->value / std::stod(rhs.toString());
        return this->myFactory->createOperand(this->biggerType( rhs ), std::to_string(result) );
    }

    IOperand const * operator%( IOperand const & rhs ) const {
        long double result = fmod(this->value, std::stod(rhs.toString()));
        return this->myFactory->createOperand(this->biggerType( rhs ), std::to_string(result) );
    }

    void    isOverflow( eOperandType type, long double result) const{
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
                if (result > std::numeric_limits<float_t>::max() || result < std::numeric_limits<float_t>::min())
                    throw AVMException("AVMException::FLOAT: over/underflow detected");
                break;
            case DOUBLE:
                if (result > std::numeric_limits<double_t>::max() || result < std::numeric_limits<double_t>::min())
                    throw AVMException("AVMException::DOUBLE: over/underflow detected");
                break;
        }
    }

protected:

private:

};

#endif