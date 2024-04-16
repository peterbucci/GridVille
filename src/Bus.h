#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"

class Bus : public Vehicle
{
public:
    Bus(string name, Intersection *startLocation, Direction startDirection);
};

#endif
