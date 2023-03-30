#include "armstrong_numbers.h"
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>

namespace armstrong_numbers {
bool is_armstrong_number(int number)
{
    const std::string s = std::to_string(number);
    const std::size_t len = s.length();

    std::vector<int> v;
    std::transform(s.begin(), s.end(), std::back_inserter(v), [len](const char c){return pow((c - '0'),len);});
    int arms_numb = std::accumulate(v.begin(), v.end(), 0);

    return (arms_numb == number);
}

}  // namespace armstrong_numbers
