// namespace Foo
// {
// 	int	gl_var = 3;
// 	int	f(void) {return 4;}
// }

#include <iostream>

int	main(void) {
	// char		buff[512];
	std::string buff;

	std::cout << "Hello world!" << std::endl;

	std::cout << "Input a word: ";
	// std::cin >> buff;
	std::getline(std::cin, buff);
	std::cout << "You entered: [" << buff << "]" << std::endl;

	return (0);
}