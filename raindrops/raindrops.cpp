#include "raindrops.h"

namespace raindrops {
std::string convert(const std::uint32_t val)
{
    const bool div_by_3 = (val % 3) == 0;
    const bool div_by_5 = (val % 5) == 0;
    const bool div_by_7 = (val % 7) == 0;

    if (div_by_3 == false && div_by_5 == false && div_by_7 == false)
    {
        return std::to_string(val);
    }

    std::string sRet;

    if(div_by_3)
        sRet += "Pling";

    if(div_by_5)
        sRet += "Plang";

    if(div_by_7)
        sRet += "Plong";

    return sRet;
}

}  // namespace raindrops
