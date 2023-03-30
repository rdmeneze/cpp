#include "triangle.h"

namespace triangle {
    bool check(double a, double b, double c)
    {
        // check condition
        if ((a + b <= c) || (a + c <= b) || (b + c <= a))
            return false;
        else
            return true;
    }

    flavor kind(const double a, const double b, const double c)
    {
        if(a <= 0 || b <= 0 || c <= 0)
        {
            throw std::domain_error(" ");
        }

        const bool isTriangle = check(a, b, c);

        if(isTriangle)
        {
            if(a == b && b == c)
                return flavor::equilateral;

            if(a == b || a == c || b == c)
                return flavor::isosceles;

            return flavor::scalene;
        }
        else
        {
            throw std::domain_error(" ");
        } 
        return flavor::isosceles;
    }


}  // namespace triangle
