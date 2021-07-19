#include "initial.h"

std::vector<int> initial_distribution(const std::vector<int> row)
{
	//We start with a vector which is zeroed out
	std::vector<int> result(length, 0);

	//More or less in the middle we place a living cell
	result[length / 2] = 1;

	return result;
}