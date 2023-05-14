#include <iostream>
#include "Sample.hpp"

int	main(void) {
	Sample instance;

	instance.publicFoo = 42;
	std::cout << "instance.publicFoo: " << instance.publicFoo << std::endl;

	instance.publicBar();

	return (0);
}
