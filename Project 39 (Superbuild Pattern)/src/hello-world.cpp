#include <iostream>
#include <cstdlib>
#include <string>

std::string say_hello()
{
	return std::string("Hello, CMake superbuild world");
}

int main()
{
	std::cout << say_hello() << '\n';
	return 0;
}