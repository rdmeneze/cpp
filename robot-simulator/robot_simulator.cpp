#include "robot_simulator.h"

namespace robot_simulator {

std::pair<int, int> Robot::get_position()
{
    return {0,0};
}

Bearing Robot::get_bearing()
{
    return Bearing::NORTH;
}

}  // namespace robot_simulator
