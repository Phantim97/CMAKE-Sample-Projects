#include "evolution.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>
#include <vector>

TEST_CASE("Apply Rule 90", "[rule-90]")
{
	std::vector<int> row = { 0, 1, 0, 1, 0, 1, 0, 1, 0 };
	std::string rule = "01011010";
	std::vector<int> expected_result = { 1, 0, 0, 0, 0, 0, 0, 0, 1 };
	REQUIRE(evolve(row, rule) == expected_result);
}

TEST_CASE("Apply Rule 222", "[rule-222]")
{
	std::vector<int> row = { 0, 0, 0, 0, 1, 0, 0, 0, 0 };
	std::string rule = "11011110";
	std::vector<int> expected_result = { 0, 0, 0, 1, 1, 1, 0, 0, 0 };
	REQUIRE(evolve(row, rule) == expected_result);
}