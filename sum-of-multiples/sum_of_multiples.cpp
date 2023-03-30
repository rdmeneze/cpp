#include "sum_of_multiples.h"
#include <numeric>
#include <set>

namespace sum_of_multiples {
std::uint64_t to(std::vector<std::uint32_t> base, std::uint64_t limit)
{
    std::vector<std::uint32_t> partial;

    for(auto num : base)
    {
        for(std::uint32_t n = 1; (n * num) < limit; n++)
        {
            partial.push_back( n*num );
        }
    }

    std::set<std::uint32_t> s(partial.begin(), partial.end());
    partial.assign(s.begin(), s.end());

    std::uint64_t ret = std::accumulate(partial.begin(), partial.end(), 0);

    return ret;
}
}  // namespace sum_of_multiples
