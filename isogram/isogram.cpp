#include "isogram.h"
#include <cctype>
#include <algorithm>

namespace isogram {
bool is_isogram(std::string word)
{
    const size_t len{word.length()};
    bool ret = true;

    if (len == 0)
        return true;

    std::transform(word.begin(), word.end(), word.begin(), tolower);

    for(size_t index = 0; index < len - 1; index++)
    {
        auto c = word[index];

        if (isalpha(c))
        {
            if(std::string::npos != word.find(c, index + 1))
            {
                ret = false;
                break;
            }
        }
    }
    return ret;
}

}  // namespace isogram
