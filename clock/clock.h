#if !defined(CLOCK_H)
#define CLOCK_H

#include <string>
#include <cstdint>

namespace date_independent
{
    class clock
    {
    public:
        clock(int hours, int minutes) noexcept;
        int hour() const noexcept;
        int minute() const noexcept;
        int minutes() const noexcept;
        clock plus(int min) const noexcept;
        clock minus(int min) const noexcept;
        explicit operator std::string() const;
    public:
        static clock at(int hours, int minutes) noexcept;
    private:
        int minutes_;
    };

    clock operator+(clock lhs, int minutes) noexcept;
    clock operator-(clock lhs, int minutes) noexcept;
    bool operator==(clock lhs, clock rhs) noexcept;
    bool operator!=(clock lhs, clock rhs) noexcept;
}  // namespace date_independent

#endif // CLOCK_H
