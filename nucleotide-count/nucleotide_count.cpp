#include "nucleotide_count.h"
#include <algorithm>

namespace nucleotide_count {

counter::counter(std::string lDna): mDna(lDna)
{
    if(mDna.find_first_not_of(nucleotide_list) != std::string::npos)
    {
        throw std::invalid_argument("");
    }

    for(auto c : nucleotide_list)
    {
        mCounts[c] = std::count(mDna.begin(), mDna.end(), c);
    }
}

std::map<char, int> counter::nucleotide_counts() const
{
    return mCounts;
}

int counter::count(char n) const
{

    auto itr = mCounts.find(n);
    if (itr == mCounts.end())
        throw std::invalid_argument("");

    return itr->second;
}

}  // namespace nucleotide_count
