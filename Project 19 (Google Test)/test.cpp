#include "sum_ints.h"
#include "gtest/gtest.h"

#include <vector>

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

	return 0;
}

TEST(example, sum_zero)
{
	std::vector<int> integers = { -3, -2, -1, 1, 2, 3 };
	int res = sum_integers(integers);
	ASSERT_EQ(res, 0);
}

TEST(example, sum_fifteen)
{
	std::vector<int> integers = { 1, 2, 3, 4, 5 };
	int res = sum_integers(integers);
	ASSERT_EQ(res, 15);
}