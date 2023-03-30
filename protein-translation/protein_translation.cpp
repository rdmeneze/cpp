#include "protein_translation.h"

#include <map>

namespace protein_translation {

const std::map<std::string, std::string> table_codon_protein{
    { "AUG" , "Methionine"},
    { "UUU" , "Phenylalanine"},
    { "UUC" , "Phenylalanine"},
    { "UUA" , "Leucine"},
    { "UUG" , "Leucine"},
    { "UCU" , "Serine"},
    { "UCC" , "Serine"},
    { "UCA" , "Serine"},
    { "UCG" , "Serine"},
    { "UAU" , "Tyrosine"},
    { "UAC" , "Tyrosine"},
    { "UGU" , "Cysteine"},
    { "UGC" , "Cysteine"},
    { "UGG" , "Tryptophan"},
    { "UAA" , "STOP"},
    { "UAG" , "STOP"},
    { "UGA" , "STOP"},
};

std::vector<std::string> proteins(const std::string rna_sequence)
{
    std::string _rna_sequence = std::move(rna_sequence);

    int leftover = _rna_sequence.length() % 3;

    if(leftover)
    {
        _rna_sequence.erase(_rna_sequence.length() - leftover - 1, leftover);
    }

    std::vector<std::string> proteins;

    for( unsigned int index = 0; index < _rna_sequence.length(); index += 3 )
    {
        std::string codon = _rna_sequence.substr(index, 3);
        auto it = table_codon_protein.find(codon);
        if(it != table_codon_protein.end())
        {
            if(it->second.compare("STOP") == 0)
                break;

            proteins.push_back( it->second );
        }
    }

    return proteins;
}


}  // namespace protein_translation
