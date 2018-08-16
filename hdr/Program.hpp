#ifndef PROGRAM_H
# define PROGRAM_H

#include <vector>
#include <string>

struct program{

int							lineNumber;
std::vector<std::string>	lineContents;
std::string					type;
std::string					value;
std::string					instruction;

};

#endif