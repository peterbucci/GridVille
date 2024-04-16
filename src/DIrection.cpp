#include "Direction.h"

ostream &operator<<(ostream &os, const Direction &direction)
{
    switch (direction)
    {
    case Direction::NORTH:
        os << "North";
        break;
    case Direction::EAST:
        os << "East";
        break;
    case Direction::SOUTH:
        os << "South";
        break;
    case Direction::WEST:
        os << "West";
        break;
    }
    return os;
}
