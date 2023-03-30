#include "gigasecond.h"

namespace gigasecond {
ptime advance(ptime n)
{
    n=n+ seconds(1000000000);
    return n;
}
}  // namespace gigasecond
