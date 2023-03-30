#if !defined(TRIANGLE_H)
#define TRIANGLE_H

#include <stdexcept>

namespace triangle {
    enum class flavor{
        equilateral,
        isosceles,
        scalene
    };

    flavor kind(const double a, const double b, const double c);

}  // namespace triangle

#endif // TRIANGLE_H
