#include "say.h"
#include <map>
#include <vector>
#include <stdexcept>
#include <cstdint>

namespace say {

    constexpr auto max_number = 999'999'999'999ull;
    const std::map<std::uint64_t, std::string> numStringTable = 
    {
        {   0,              "zero"          },  {   1,              "one"           },  {   2,              "two"           },  
        {   3,              "three"         },  {   4,              "four"          },  {   5,              "five"          },
        {   6,              "six"           },  {   7,              "seven"         },  {   8,              "eight"         },  
        {   9,              "nine"          },  {  10,              "ten"           },  {  11,              "eleven"        },
        {  12,              "twelve"        },  {  13,              "thirteen"      },  {  14,              "fourteen"      },
        {  15,              "fifteen"       },  {  16,              "sixteen"       },  {  17,              "seventeen"     },  
        {  18,              "eighteen"      },  {  19,              "nineteen"      },  {  20,              "twenty"        },  
        {  30,              "thirty"        },  {  40,              "forty"         },  {  50,              "fifty"         },
        {  60,              "sixty"         },  {  70,              "seventy"       },  {  80,              "eighty"        },  
        {  90,              "ninety"        },  {  100,             "hundred"       },  {  1000,            "thousand"      },
        {  1'000'000,       "million"       },  {  1'000'000'000,   "billion"       }
    };

    template <typename T, typename U>
    inline std::string n_hundreds(const T number, const U power_of_ten) 
    {
        const std::size_t mul_power_of_ten = number / power_of_ten;
        const std::size_t rest_power_of_ten = number % power_of_ten; 

        return in_english(mul_power_of_ten) + ' ' + numStringTable.at(power_of_ten) + 
            (rest_power_of_ten != 0 ? ' ' + in_english(rest_power_of_ten) : "");
    }

    std::string in_english(const std::uint64_t num)
    {
        if(num > max_number)
        {
            throw std::domain_error{"Number out of range."};
        }

        if (num >= 1'000'000'000) 
        {
            return n_hundreds(num, 1'000'000'000);
        }
        else if (num >= 1000000) 
        {
            return n_hundreds(num, 1000000);
        } 
        else if (num >= 1000) 
        {
            return n_hundreds(num, 1000);
        } 
        else if (num >= 100) 
        {
            return n_hundreds(num, 100);
        } 
        else if (num > 20) 
        {
            return numStringTable.at((num / 10) * 10) + '-' + numStringTable.at(num % 10);
        } 
        else 
        {
            return numStringTable.at(num);
        } 
    }
}  // namespace say
