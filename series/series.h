#if !defined(SERIES_H)
#define SERIES_H

#include <vector>
#include <string>

namespace series {
std::vector<int> digits(std::string n);
std::vector<std::vector<int>> slice(std::string n, uint8_t len);
}  // namespace series

#endif // SERIES_H
