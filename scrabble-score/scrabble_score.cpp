#include "scrabble_score.h"

#include <map>
#include <cstdint>
#include <cctype>
#include <numeric>
#include <algorithm>
#include <set>

namespace scrabble_score {

const std::map<std::set<char>, std::uint8_t> conv_table
{
    {{'A','E','I','O','U','L','N','R','S','T'},1},
    {{'D','G'},2},
    {{'B','C','M','P'},3},
    {{'F','H','V','W','Y'},4},
    {{'K'},5},
    {{'J','X'},8},
    {{'Q','Z'},10},
};

int get_score(const char &c)
{
    for(const auto &[key, value] : conv_table)
    {
        if(key.count(std::toupper(c)))
            return value;
    }
    return 0;
}

int score(const std::string s)
{
    std::vector<int> v;
    std::transform(s.begin(), s.end(), std::back_inserter(v), [](const char c){return get_score(c);});
    const int res = std::accumulate( v.begin(), v.end(), 0 );
    return res;
}

}  // namespace scrabble_score
