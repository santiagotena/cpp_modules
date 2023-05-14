#include <iostream>
#include "Sample.hpp"

int	main(void) {
	Sample 	instance;
	Sample	*instancePtr = &instance;

	int		Sample::*p = NULL;
	void	(Sample::*f)(void) const;

	p = &Sample::foo;

	std::cout << "Value of member foo: " << instance.foo << std::endl;
	instance.*p = 21;
	std::cout << "Value of member foo: " << instance.foo << std::endl;
	instancePtr->*p = 42;
	std::cout << "Value of member foo: " << instance.foo << std::endl;
	
	f = &Sample::bar;

	(instance.*f)();
	(instancePtr->*f)();

	return (0);
}