#include "hamming.h"

namespace hamming {
unsigned int compute(std::string seq_a, std::string seq_b)
{
    if(seq_a.length() != seq_b.length())
    {
        throw std::domain_error("");
    }

    unsigned int distance = 0;
    for(unsigned int i = 0; i < seq_a.length(); i++)
    {
        if(seq_a[i] != seq_b[i])
        {
            distance++;
        }
    }

    return distance;

}
}  // namespace hamming
