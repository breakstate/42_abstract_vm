#include "../hdr/IOperand.hpp"
#include <iostream>
#include <string>

int		main()
{
	Operator <int> first( 5, "int", 0);
	Operator <int> second( 50, "int", 0);
	IOperand const *third;
	IOperand const *fourth;

	
	
	std::cout << first.value << std::endl;
	std::cout << second.value << std::endl;

	std::cout << second.toString() << std::endl;
	third = first + second;
	fourth = *third - second;
	
	return (0);
}
