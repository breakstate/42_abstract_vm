# 42_abstract_vm
A 42 / WeThinkCode project
## General overview
AbstractVM is a simple virtual machine that uses a stack to compute simple arithmetic expressions.
These arithmetic expressions are provided to the virtual machine as basic assembly programs in the form of a file or read from stdin, implemented in C++.

## Key requirements
- Must make use of IOperand abstract class (interface) provided
- Must make use of a Factory method to create operands
- Must handle errors in a non-scalar manner

## Key components
### Lexer<br>
The Lexer decides whether or not an input file is present. If not, the program will wait on input from stdin. 
Lines are tokenized within the lexer and unrecognized tokens throw errors. Lexer will report all errors found including on which line the error occurred.
### Parser
The Parser tells the Stack which operations to perform, after having receiving clean tokens from the Lexer.
### Stack class
The Stack class performs operations on the values within the stack object.
### Factory
The factory method creates Operand objects based on instructions received from the Stack class.
### Operands
Inherits from the given IOperand interface.
