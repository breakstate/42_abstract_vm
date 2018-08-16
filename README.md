# 42_abstract_vm
## General overview
AbstractVM is a simple virtual machine that uses a stack to compute simple arithmetic expressions.
These arithmetic expressions are provided to the virtual machine as basic assembly programs in the form of a file or read from stdin, implemented in C++.

## Key requirements
- Must make use of IOperand abstract class (interface) provided
- Must make use of a Factory method to create operands
- Must handle errors in a non-scalar manner

## Key components
###Lexer<br>
The Lexer decides whether or not an input file is preset. If not, the program will wait on input from stdin.
- Parser
- Stack
- Factory
- Operands
