#include "../hdr/AVMException.hpp"

AVMException::AVMException( void ) {

}

AVMException::AVMException( const AVMException & srcObj ) {
	this->operator=(srcObj);
}

AVMException & AVMException::operator=( AVMException const & rhs ) {
	this->_errorMessage = rhs._errorMessage;
	return (*this);
}

AVMException::AVMException( std::string errorMessage ) {
	this->_errorMessage = errorMessage;
}

AVMException::~AVMException() throw() {
}

const char* AVMException::what() const throw() {
	return (this->_errorMessage.c_str());
}