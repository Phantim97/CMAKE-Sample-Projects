#include "conversion.h"
#include <bitset>

std::string binary_representation(const int decimal)
{
	return std::bits<8>(decimal).to_string();
}