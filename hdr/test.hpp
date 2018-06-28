#ifndef TEST_H
# define TEST_H
# include "../hdr/IOperand.hpp"
# include <string>

class test : public IOperand {

    public:
    test( void );
    ~test( void );
    std::string const & toString( void ) const;



    int val;

};


#endif