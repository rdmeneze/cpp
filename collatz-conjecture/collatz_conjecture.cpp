#include "collatz_conjecture.h"
#include <stdexcept>
#include <iostream>

namespace collatz_conjecture {
int steps(const int n)
{
    static int step_count=0;

    if(n <= 0)
    {
        step_count = 0;
        throw std::domain_error("");
    }

    if(n == 1)
    {
        int ret = step_count;
        step_count = 0;
        return ret;
    }

    step_count++;
    return steps( (n % 2 == 0) ? n/2 : (n*3) + 1);
}
}  // namespace collatz_conjecture
