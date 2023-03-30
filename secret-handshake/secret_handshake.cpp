#include "secret_handshake.h"

#include <map>
#include <cstdint>
#include <bitset>
#include <array>
#include <algorithm>

namespace secret_handshake {
std::vector<std::string> commands(const int cmd)
{
    const std::array<const char*, 4> handshake = {
        "wink",
        "double blink",
        "close your eyes",
        "jump",
    };
    std::vector<std::string> shake;

    for(std::uint8_t index = 0; index < 5; index++)
    {
        if(cmd & (1 << index))
        {
            if(index == 4)
            {
                std::reverse(shake.begin(), shake.end());
                break;
            }
            else
            {
                shake.push_back(handshake[index]);
            }
        }
    }

    return shake;
}

}  // namespace secret_handshake
