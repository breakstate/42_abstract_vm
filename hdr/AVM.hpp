#ifndef AVM_H
# define AVM_H

# include "Parser.hpp"
# include "Lexer.hpp"
# include "Program.hpp"

class AVM{

public:

AVM( void );
AVM( const AVM & srcObj );
AVM & operator=( AVM const & rhs );
~AVM( void );

void	run( int argc, char **argv );

protected:

private:

std::array<std::string, 12>		_instructionSet;
std::array<std::string, 5>		_typeSet;
Lexer*							_lexer;
Parser*							_parser;
std::vector<program>			_program;

};

#endif