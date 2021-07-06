#include <iostream>
#include <string>

std::string hello()
{
	return std::string("Hello CMAKE\n");
}

int main()
{
	std::cout << hello();
	return 0;
}