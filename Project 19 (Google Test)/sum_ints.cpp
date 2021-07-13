#include "sum_ints.h"

int sum_integers(const std::vector<int> integers)
{
	int sum = 0;

	for (int i = 0; i < integers.size(); i++)
	{
		sum += integers[i];
	}

	return sum;
}
