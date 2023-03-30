#include "reverse_string.h"

namespace reverse_string {
std::string reverse_string(std::string s)
{
    std::string ret;

    for(std::string::reverse_iterator rit = s.rbegin(); rit != s.rend(); ++rit)
    {
        ret.append(1, *rit);
    }

    return ret;
}

}  // namespace reverse_string
