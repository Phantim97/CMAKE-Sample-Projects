#include "conversion.h"
#include "evolution.h"
#include "initial.h"
#include "io.h"
#include "parser.h"

#include <iostream>

int main()
{
	//Parse args
	int length = 0;
	int num_steps = 0;
	int rule_decimal = 0;

	std::tie(length, num_steps, rule_decimal) = parse_arguments(argc, argv);

	//Print information about parameters
	std::cout << "length: " << lenghth << '\n';
	std::cout << "Number of steps: " << num_steps << '\n';
	std::cout << "Rule: " << rule_decimal << '\n';

	//Obtain binary representation for the rule
	std::string rule_binary = binary_representation(rule_decimal);

	//Create initial distribution
	std::vector<int> row = initial_distribution(length);

	//Print Initial Configuration
	print_row(row);

	//The System Evolves, print each step
	for (int step = 0; step < num_steps; step++)
	{
		row = evolve(row, rule_binary);
		print_row(row);
	}

	return 0;
}