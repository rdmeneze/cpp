#include "rna_transcription.h"
#include <map>

namespace rna_transcription {

const std::map<char, char> dna_rna_conv_table{ {'G', 'C'}, {'C', 'G'}, {'T', 'A'}, {'A','U'} };


char to_rna(const char dna)
{
    auto it = dna_rna_conv_table.find(dna);
    if(it != dna_rna_conv_table.end())
    {
        return it->second;
    }
    return '\0';
}

std::string to_rna(const std::string dna)
{
    std::string rna;

    for(auto c : dna)
    {
        auto it = dna_rna_conv_table.find(c);
        if(it != dna_rna_conv_table.end())
        {
            rna += it->second;
        }

    }
    return rna;
}

}  // namespace rna_transcription
