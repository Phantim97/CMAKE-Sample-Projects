#include "parser.h"
#include <cassert>
#include <string>

std::tuple<int, int, int> parse_arguments(int argc, char* argv[])
{
	assert(argc == 4 && "program called with wrong number of arguments");

	int length = std::stoi(argv[1]);
	int num_steps = std::stoi(argv[2]);
	int rule_decimal = std::stoi(argv[3]);

	return std::make_tuple(length, num_steps, rule_decimal);
}