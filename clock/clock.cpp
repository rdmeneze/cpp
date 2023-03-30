#include "clock.h"
#include <cassert>
#include <cstdio>

constexpr int positive_modulo(int dividend, int divisor)
{
    return dividend % divisor + (dividend >= 0? 0: divisor);
}

date_independent::clock::clock(int hours, int minutes) noexcept
    : minutes_(positive_modulo(hours * 60 + minutes, 24 * 60))
{
    assert(0 <= minutes_ && minutes_ < 24 * 60);
}

int date_independent::clock::hour() const noexcept
{
    return minutes_ / 60;
}

int date_independent::clock::minute() const noexcept
{
    return minutes_ % 60;
}

int date_independent::clock::minutes() const noexcept
{
    return minutes_;
}

date_independent::clock date_independent::clock::plus(int min) const noexcept
{
    return clock(0, minutes_ + min);
}

date_independent::clock date_independent::clock::minus(int min) const noexcept
{
    return clock(0, minutes_ - min);
}

date_independent::clock::operator std::string() const
{
    assert(0 <= minutes_ && minutes_ < 24 * 60);
    char buffer[6];
    std::sprintf(buffer, "%02d:%02d", minutes_ / 60, minutes_ % 60);
    return buffer;
}

date_independent::clock date_independent::clock::at(int hours, int min) noexcept
{
    return clock(hours, min);
}

date_independent::clock date_independent::operator+(clock lhs, int min) noexcept
{
    return lhs.plus(min);
}

date_independent::clock date_independent::operator-(clock lhs, int min) noexcept
{
    return lhs.minus(min);
}

bool date_independent::operator==(clock lhs, clock rhs) noexcept
{
    return lhs.minutes() == rhs.minutes();
}

bool date_independent::operator!=(clock lhs, clock rhs) noexcept
{
    return !(lhs == rhs);
}
