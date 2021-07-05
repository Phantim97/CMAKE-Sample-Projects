#include <cstdlib>
#include <iostream>
#include <string>

std::string say_hello()
{
#ifdef IS_WINDOWS
	return std::string("Hello from Windows");
#elif IS_LINUX
	return std::string("Hello from Linux");
#elif IS_MACOS
	return std::string("Hello from Mac OS");
#else
	return std::string("Hello from Unknown System");
#endif
}

int main()
{
	std::cout << say_hello() << '\n';
	return 0;
}