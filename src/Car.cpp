#include "Car.h"

Car::Car(string name, Intersection *startLocation, Direction startDirection)
    : Vehicle(name, startLocation, startDirection) {}

bool Car::canStopHere(Intersection *intersection)
{
    return !intersection->getIsBusStop(); // Cars can't stop at bus stops
}