#include "series.h"
#include <stdexcept>

namespace series{

bool isvalid(std::string n)
{
    if(n.find_first_not_of("0123456789") != std::string::npos)
        return false;
    return true;
}

std::vector<int> digits(std::string n)
{
    std::vector<int> res{};

    if(!isvalid(n))
        return res;

    for(auto c : n)
    {
        res.push_back(c - '0');
    }

    return res;
}

std::vector<std::vector<int>> slice(std::string n, uint8_t len)
{
    (void)n;
    (void)len;

    std::vector<std::vector<int>> res;

    const std::vector<int> dig = digits(n);

    if(len > dig.size())
    {
        throw std::domain_error(" ");
    }

    for(size_t index = 0; index <= (dig.size() - len); index++)
    {
        std::vector<int> sub_digs;

        for(size_t ii = index; ii < len+index; ii++)
        {
            sub_digs.push_back(dig[ii]);
        }

        res.push_back(sub_digs);
    }

    return res;
}


}  // namespace series
