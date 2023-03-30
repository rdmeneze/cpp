#include "difference_of_squares.h"

namespace difference_of_squares {
std::uint32_t square_of_sum(const std::int16_t n)
{
    std::uint32_t sum = 0;

    for(std::int16_t counter = n; counter; counter--)
    {
        sum += counter;
    }
    return sum * sum;
}

std::uint32_t sum_of_squares(const std::int16_t n)
{
    std::uint32_t sum = 0;

    for(std::int16_t counter = n; counter; counter--)
    {
        sum += (counter * counter);
    }
    return sum;

}

std::uint32_t difference(const std::int16_t n)
{
    return square_of_sum(n) - sum_of_squares(n);
}

}  // namespace difference_of_squares
