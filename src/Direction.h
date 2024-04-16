#ifndef DIRECTION_H
#define DIRECTION_H

#include <iostream>

using namespace std;

enum class Direction
{
    NORTH,
    EAST,
    SOUTH,
    WEST
};

ostream &operator<<(ostream &os, const Direction &direction);

#endif
