#include "sum_ints.h"

#include <vector>

int main() 
{
    std::vector<int> integers = { 1, 2, 3, 4, 5 };

    if (sum_integers(integers) == 15) 
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}