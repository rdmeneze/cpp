#include "atbash_cipher.h"
#include <algorithm>
#include <iterator>
#include <cstdint>
#include <cctype>

namespace atbash_cipher {

const std::string plain = "abcdefghijklmnopqrstuvwxyz";
const std::string cypher(plain.rbegin(), plain.rend());

std::string encode(std::string message)
{
    std::string result = "";
    int count = 0;
    for(char &c : message)
    {
        auto i = plain.find(tolower(c));
        if(i != std::string::npos)
        {
            result+=cypher[i];

            count++;
            count%=5;

            if(count == 0)
                result += " ";
        }
        else if(isalnum(c))
        {
            result+=c;

            count++;
            count%=5;

            if(count == 0)
                result += " ";
        }
    }

    if (result.find_last_of(" ") == result.length() -1)
        result.pop_back();

    return result;
}

std::string decode(std::string message)
{
    std::string result = "";

    for(char &c : message)
    {
        auto i = cypher.find(tolower(c));
        if(i != std::string::npos)
        {
            result+=plain[i];
        }
        else if(isalnum(c))
        {
            result+=c;
        }
    }
    return result;
}


}  // namespace atbash_cipher
