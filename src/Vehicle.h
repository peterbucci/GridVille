#ifndef VEHICLE_H
#define VEHICLE_H

#include "Intersection.h"
#include "Direction.h"
#include <string>

using namespace std;

class Vehicle
{
private:
    string name;            // The name of the vehicle.
    Intersection *location; // The intersection where the vehicle is located.
    Direction direction;    // The direction the vehicle is facing.

public:
    // Constructor for a vehicle.
    Vehicle(string name, Intersection *startLocation, Direction startDirection);
    // Getter for the name of the vehicle.
    string getName() const;
    Intersection *getLocation() const;
    Direction getDirection() const;
    // Setter for the name of the vehicle.
    void setName(string newName);
    void setLocation(Intersection *newLocation);
    void setDirection(Direction newDirection);
    // Methods to move and stop the vehicle.
    void turnRight();
    void turnLeft();
    virtual bool canStopHere(Intersection *intersection);
    bool drive();
};

#endif
