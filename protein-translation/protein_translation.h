#if !defined(PROTEIN_TRANSLATION_H)
#define PROTEIN_TRANSLATION_H

#include <string>
#include <vector>

namespace protein_translation {

std::vector<std::string> proteins(const std::string rna_sequence);

}  // namespace protein_translation

#endif // PROTEIN_TRANSLATION_H
