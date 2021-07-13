#include <iostream>
#include <string>
#include "sum_ints.h"

//assume args are ints that we sum up for simplicity args not verified
int main(int argc, char* argv[])
{
	std::vector<int> integers;

	for (int i = 1; i < argc; i++)
	{
		integers.push_back(std::stoi(argv[i]));
	}

	int sum = sum_integers(integers);

	std::cout << sum << '\n';

	return 0;
}