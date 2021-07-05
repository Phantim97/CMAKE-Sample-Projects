#include <cstdlib>
#include <iostream>
#include <string>

std::string say_hello()
{
#ifdef IS_INTEL_CXX_COMPILER
	return std::string("Hello from Intel Compiler");
#elif IS_GNU_CXX_COMPILER
	return std::string("Hello GNU Compiler!");
#elif IS_PGI_CXX_COMPILER
	return std::string("Hello PGI Compiler");
#elif IS_XL_CXX_COMPILER
	return std::string("Hello XL Compiler");
#elif IS_WIN_CXX_COMPILER
	return std::string("Hello MSVC Compiler");
#else
	return std::string("Hello Unknown Compiler");
#endif
}

int main()
{
	std::cout << say_hello() << '\n';
	return 0;
}