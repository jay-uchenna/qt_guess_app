#include "RANDOM.h"
#include <iostream>


int random_number(int first_range, int last_range)
{

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni( first_range, last_range);

    return uni(rng);

}
