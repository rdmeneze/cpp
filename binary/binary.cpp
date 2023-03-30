#include "binary.h"
#include <cmath>

namespace binary
{

std::uint64_t convert(const std::string &bin_num)
{
    const std::size_t len = bin_num.length();
    std::uint64_t res = 0;

    for(std::size_t index = 0; index < len; index++)
    {
        auto c = bin_num[index];
        if((c == '1') || (c == '0'))
        {
            std::uint8_t dig = bin_num[index] == '1' ? 1 : 0;
            res += ( (std::uint64_t)dig * (std::uint64_t)(dig << (len - index - 1)) );
        }
        else
        {
            res = 0;
            break;
        }
    }

    return res;
}


}  // namespace binary
