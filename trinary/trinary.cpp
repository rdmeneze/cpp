#include "trinary.h"
#include <math.h>

namespace trinary {

unsigned int to_decimal(std::string number)
{
    int result = 0;
    for (auto c: number)
    {
        if (c < '0' || c > '2')
            return 0;
        result = result * 3 + (c - '0');
    }
    return result;
}

}  // namespace trinary
