#if !defined(SPACE_AGE_H)
#define SPACE_AGE_H

#include <cstdint>

namespace space_age {

class space_age{
public:
    space_age(const std::uint64_t t) : time_seconds(t) {}
    std::uint64_t seconds() const{ return time_seconds;}
    double on_earth() const{ return seconds() / 31557600.;}
    double on_mercury() const{ return on_earth()/0.2408467;}
    double on_venus()  const{ return on_earth()/0.61519726;}
    double on_mars()  const{ return on_earth()/1.8808158;}
    double on_jupiter()  const{ return on_earth()/11.862615;}
    double on_saturn()  const{ return on_earth()/29.447498;}
    double on_uranus()  const{ return on_earth()/84.016846;}
    double on_neptune()  const{ return on_earth()/164.79132;}
private:
    std::uint64_t time_seconds;
};


}  // namespace space_age

#endif // SPACE_AGE_H
