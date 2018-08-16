#ifndef PARSER_H
# define PARSER_H

# include <string>

# include "Lexer.hpp"
# include "Type.hpp"
# include "Stack.hpp"
# include "AVMException.hpp"

class Parser {

public:

Parser( void );
Parser( const Parser & srcObj );
Parser & operator=( Parser const & rhs );
~Parser( void );
void			execute( std::vector<program> program );
void			inputOverflow( eOperandType type, std::string value );
eOperandType	interpretType( const std::string value );

protected:

private:

Stack			_stackObject;
std::string		_parseErrors;

};

#endif