#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H

#include <map>
#include <string>

namespace nucleotide_count {

class counter
{
public:
    counter(std::string);
    std::map<char, int> nucleotide_counts() const;
    int count(char) const;

private:
    std::string mDna;
    std::map<char, int> mCounts;

    const std::string nucleotide_list{'A', 'C', 'G', 'T'};
};

}  // namespace nucleotide_count

#endif // NUCLEOTIDE_COUNT_H
