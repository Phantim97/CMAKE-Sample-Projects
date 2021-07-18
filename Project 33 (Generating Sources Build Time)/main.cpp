#include "primes.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::cout << "all prime numbers up to " << max_number << ": ";

	std::vector<int> p = primes();

	for (int i = 0; i < p.size(); i++)
	{
		std::cout << p[i] << " ";
	}

	std::cout << '\n';

	return 0;
}