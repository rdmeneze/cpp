#if !defined(ALLERGIES_H)
#define ALLERGIES_H

#include <map>
#include <string>
#include <cstdint>
#include <unordered_set>
#include <algorithm>

namespace allergies {

class allergy_test
{
public:
    allergy_test( const std::uint32_t allergie_score )
    {
        for( std::size_t index = 0; index < allergies_names_table.size(); index++ )
        {
            if(allergie_score & (1 << index))
            {
                auto it = allergies_names_table.find((1 << index));

                if(it != allergies_names_table.end())
                {
                    cur_allergies.insert( it->second );
                }
            }
        }
    }

    bool is_allergic_to(const std::string &source)
    {
        return (cur_allergies.find(source) != cur_allergies.end()) ? true : false;
    }

    std::unordered_set<std::string> get_allergies() const
    {
        return cur_allergies;
    }

private:
    const std::map<std::uint8_t, std::string> allergies_names_table
    {
        {1,   "eggs"},
        {2,   "peanuts"},
        {4,   "shellfish"},
        {8,   "strawberries"},
        {16,  "tomatoes"},
        {32,  "chocolate"},
        {64,  "pollen"},
        {128, "cats"},
    };

    std::unordered_set<std::string> cur_allergies;
};

}  // namespace allergies

#endif // ALLERGIES_H
