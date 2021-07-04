#include <iostream>
#include "Message.h"

int main()
{
	Message say_hi("Hello, CMake World");
	std::cout << say_hi << '\n';

	Message say_goodbye("Goodbye,  CMAKE World");
	std::cout << say_goodbye << '\n';

	return 0;
}