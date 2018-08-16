#include "../hdr/Stack.hpp"
#include "../hdr/IOperand.hpp"
#include "../hdr/AVMException.hpp"

Stack::Stack ( void ) {
}

Stack::Stack( const Stack & srcObj ) {
	this->operator=(srcObj);
}

Stack & Stack::operator=( Stack const & rhs ) {
	this->_myFactory = rhs._myFactory;
	this->_myStack = rhs._myStack;
	return (*this);
}

Stack::~Stack ( void ) {
}

void	Stack::restack( IOperand const * result ) {
	this->pop();
	this->pop();
	this->_myStack.insert(this->_myStack.begin(), result);
}

// pushes values to the top of the stack
void	Stack::push( eOperandType type, std::string strValue ) {
	const IOperand *newElement = this->_myFactory.createOperand( type, strValue );
	this->_myStack.insert(this->_myStack.begin(), newElement);
}

// unstacks value on top of the stack, if empty exit with error
void	Stack::pop() {
	if (this->_myStack.size() < 1)
		throw AVMException("** AVMException::pop: pop() called on empty stack");
	this->_myStack.erase(this->_myStack.begin());
}

// displays all values in stack from most recent to oldest
void	Stack::dump() {
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2);
	if (this->_myStack.size() < 1)
		std::cout << "You sure? You're dumping an empty stack there bud. Well.. Okay then." << std::endl;
	std::cout << std::endl;
	std::cout << "DUMP:" << std::endl;
	for (unsigned int i = 0; i < this->_myStack.size(); i++){
		std::cout << this->_myStack[i]->toString() << std::endl;
	}
}

// checks that value passed in as parameter has the same value as value at top of stack, exit with error if not
void	Stack::assert( eOperandType type, std::string strValue ) {
	if (this->_myStack.size() < 1){
		throw AVMException("AVMException::assert: assert() called on empty stack");
	}
	const IOperand *temp = this->_myFactory.createOperand( type, strValue );
	if (temp->toString() == this->_myStack[0]->toString() && type == this->_myStack[0]->getType())
		std::cout << "asserted" << std::endl;
	else
		throw AVMException("AVMException::assert: assert() returned false");
}

// unstacks top two elements, adds them, pushes resulting element to top // last in on the right
void	Stack::add() {
	if (this->_myStack.size() < 2){
		throw AVMException("AVMException::add: add() called with fewer than 2 values on the stack");
	}
	IOperand const * result;
	result = *this->_myStack[0] + *this->_myStack[1];
	this->restack( result );
}

// unstacks top two elements, subtracts them, pushes resulting element to top
void	Stack::sub() {
	if (this->_myStack.size() < 2){
		throw AVMException("AVMException::sub: sub() called with fewer than 2 values on the stack");
	}
	IOperand const * result;
	result = *this->_myStack[1] - *this->_myStack[0];
	this->restack( result );
}

// unstacks top two elements, multiplies them, pushes resulting element to top
void	Stack::mul() {
	if (this->_myStack.size() < 2){
		throw AVMException("AVMException::mul: mul() called with fewer than 2 values on the stack");
	}
	IOperand const * result;
	result = *this->_myStack[0] * *this->_myStack[1];
	this->restack( result );
}

// unstacks top two elements, divides them, pushes resulting element to top
void	Stack::div() {
	if (this->_myStack.size() < 2){
		throw AVMException("AVMException::div: div() called with fewer than 2 values on the stack");
	}
	if (std::stod(this->_myStack[0]->toString()) == 0){
		throw AVMException("AVMException::div: attempted division by zero");
	}
	IOperand const * result;
	result = *this->_myStack[1] / *this->_myStack[0];
	this->restack( result );
}

// unstacks top two elements, moduluses them, pushes resulting element to top
void	Stack::mod() {
	if (this->_myStack.size() < 2){
		throw AVMException("AVMException::mod: mod() called with fewer than 2 values on the stack");
	}
	if (std::stod(this->_myStack[0]->toString()) == 0){
		throw AVMException("AVMException::mod: attempted modulus by zero");
	}
	IOperand const * result;
	result = *this->_myStack[1] % *this->_myStack[0];
	this->restack( result );
}

 // if value at top of stack is int8, print as char, else exit with error like assert (just the first)
void	Stack::print() {
	if (this->_myStack.size() < 1){
		throw AVMException("AVMException::print: print() called on empty stack");
	}
	if (this->_myStack[0]->getType() != 0){
		throw AVMException("AVMException::print: print() called on non 8-bit integer");
	}
	std::cout << (char)(std::stoi(_myStack[0]->toString())) << std::endl;
}

void	Stack::exit() {
}
