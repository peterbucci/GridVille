#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle
{
public:
    Car(string name, Intersection *startLocation, Direction startDirection);
    bool canStopHere(Intersection *intersection) override;
};

#endif