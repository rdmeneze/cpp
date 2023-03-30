#if !defined(PASCALS_TRIANGLE_H)
#define PASCALS_TRIANGLE_H

#include <vector>
#include <cstdint>

namespace pascals_triangle {

const std::vector<std::vector<int>> generate_rows(std::uint8_t depth);

}  // namespace pascals_triangle

#endif // PASCALS_TRIANGLE_H
