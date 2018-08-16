#ifndef LEXER_H
# define LEXER_H

# include <string>
# include <vector>
# include <fstream>
# include <iostream>
# include <sys/stat.h>
# include <array>

# include "AVMException.hpp"
# include "Program.hpp"

class Lexer {

public:

Lexer( void );
Lexer( std::array<std::string, 12> _instructionSet, std::array<std::string, 5> _typeSet );
Lexer( const Lexer & srcObj );
Lexer & operator=( Lexer const & rhs );
~Lexer( void );
void					read( int argc, char** argv);
void					debugPrintProg( void );
std::vector<program>	getProgram( void );

protected:

private:

void	_getLines( std::string & line, size_t & pos, int & smallBreak, int & bigBreak, int & i, int & lineCount );
void	_getTokens( std::string & line, size_t & pos, int & smallBreak, int & i, int & lineCount );
void	_isValidFile( std::string filename );
void	_lexicalValidation( void );
void	_isValidInstruction( program & line );
void	_isValidType( program & line );
void	_isValidValue( program & line );
void	_isValue( program & line );

std::vector<program>			_program;
std::string						_delimiter;
std::string						_comment;
std::array<std::string, 12>		_instructionSet;
std::array<std::string, 5>		_typeSet;
std::string						_lexicalErrors;

};

#endif