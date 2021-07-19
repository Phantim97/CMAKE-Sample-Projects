#include "evolution.h"

std::vector<int> evolve(const std::vector<int> row, const std::string rule_binary)
{
	std::vector<int> result;

	for (int i = 0; i < row.size(); i++)
	{
		int left = 0;
		int center = i;
		int right = (i + 1) % row.size();

		if (i == 0)
		{
			left = row.size() - 1;
		}
		else
		{
			left = i - 1;
		}

		int ancestors = 4 * row[left] + 2 * row[center] + 1 * row[right];
		ancestors = 7 - ancestors;

		int new_state = std::stoi(rule_binary.substr(ancestors, 1));

		result.push_back(new_state);
	}

	return result;
}