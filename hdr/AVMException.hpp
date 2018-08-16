#ifndef AVMEXCEPTION_H
# define AVMEXCEPTION_H

# include <stdexcept>
# include <string>

class AVMException: public std::exception {

public:

AVMException( void );
AVMException( const AVMException & srcObj );
AVMException & operator=( AVMException const & rhs );
AVMException( std::string errorMessage );
~AVMException() throw();
const char* what() const throw();

protected:

private:

std::string _errorMessage;

};

#endif