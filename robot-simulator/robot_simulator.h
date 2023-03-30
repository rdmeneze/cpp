#if !defined(ROBOT_SIMULATOR_H)
#define ROBOT_SIMULATOR_H

#include <utility>

namespace robot_simulator {

enum class Bearing{
    NORTH,
    SOUTH,
    EAST,
    WEST
};

class Robot{
public:
    std::pair<int, int> get_position();
    Bearing get_bearing();
};


}  // namespace robot_simulator

#endif // ROBOT_SIMULATOR_H
