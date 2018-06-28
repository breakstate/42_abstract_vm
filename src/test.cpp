#include "../hdr/test.hpp"
#include "../hdr/IOperand.hpp"

test::test( void ) {
    this->val = 23;
}

test::~test( void ) {

}

std::string const & test::toString( void ) const {
    std::string str;
    str = std::to_string(this->val);
    return (str);
}
