#include "pascals_triangle.h"
#include <iostream>

namespace pascals_triangle {
const std::vector<std::vector<int>> generate_rows(std::uint8_t depth)
{
    std::vector<std::vector<int>> result;

    if(depth < 3)
    {
        if(depth == 1)
        {
            return {{1}};
        }

        if(depth == 2)
        {
            return {{1}, {1,1}};
        }

        return {};
    }

    result = {{1}, {1,1}};

    for(int i = 3; i <= depth; i++)
    {
        std::vector<int> new_line{};
        std::vector<int> &prev_line = result[i-2];

        const auto new_line_len = prev_line.size() + 1;

        new_line.push_back(prev_line[0]);

        for(std::size_t index = 1; index < new_line_len - 1; index++)
        {
            const auto new_value = prev_line[index] + prev_line[index-1];
            new_line.push_back(new_value);
        }

        new_line.push_back(prev_line[prev_line.size()-1]);

        result.push_back(new_line);
    }

    return result;
}

}  // namespace pascals_triangle
