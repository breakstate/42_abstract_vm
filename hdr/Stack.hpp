#ifndef STACK_H
# define STACK_H

# include <vector>

# include "IOperand.hpp"
# include "Factory.hpp"

class Stack {
	public:
	
	Stack( void );
	Stack( const Stack & srcObj );
	Stack & operator=( Stack const & rhs );
	~Stack( void );

	void	restack( IOperand const * result );
	void	push( eOperandType type, std::string strValue );
	void	pop();
	void	dump();
	void	assert( eOperandType type, std::string strValue );
	void	add();
	void	sub();
	void	mul();
	void	div();
	void	mod();
	void	print();
	void	exit();

	protected:

	private:
	Factory							_myFactory;
	std::vector<IOperand const *>	_myStack;

};

#endif