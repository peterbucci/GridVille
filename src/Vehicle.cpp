#include "Vehicle.h"

/**
 * Constructor for a vehicle.
 * @param name the name of the vehicle
 * @param startLocation the intersection where the vehicle starts
 * @param startDirection the direction the vehicle is facing
 */
Vehicle::Vehicle(string name, Intersection *startLocation, Direction startDirection)
    : name(name), location(startLocation), direction(startDirection) {}

/**
 * Getter for the name of the vehicle.
 * @return the name of the vehicle
 */
string Vehicle::getName() const
{
    return name;
}

/**
 * Getter for the location of the vehicle.
 * @return the location of the vehicle
 */
Intersection *Vehicle::getLocation() const
{
    return location;
}

/**
 * Getter for the direction the vehicle is facing.
 * @return the direction the vehicle is facing
 */
Direction Vehicle::getDirection() const
{
    return direction;
}

/**
 * Setter for the name of the vehicle.
 * @param newName the new name of the vehicle
 */
void Vehicle::setName(string newName)
{
    name = newName;
}

/**
 * Setter for the location of the vehicle.
 * @param newLocation the new location of the vehicle
 */
void Vehicle::setLocation(Intersection *newLocation)
{
    location = newLocation;
}

/**
 * Setter for the direction the vehicle is facing.
 * @param newDirection the new direction the vehicle is facing
 */
void Vehicle::setDirection(Direction newDirection)
{
    direction = newDirection;
}

/**
 * Turns the vehicle to the right.
 */
void Vehicle::turnRight()
{
    direction = static_cast<Direction>((static_cast<int>(direction) + 1) % 4);
}

/**
 * Turns the vehicle to the left.
 */
void Vehicle::turnLeft()
{
    direction = static_cast<Direction>((static_cast<int>(direction) + 3) % 4);
}

/**
 * Determines if the vehicle can stop at the given intersection.
 * @param intersection the intersection to check
 * @return true if the vehicle can stop, false otherwise
 */
bool Vehicle::canStopHere(Intersection *intersection)
{
    // For a generic vehicle, it can always stop.
    return true;
}

/**
 * Drives the vehicle forward. The vehicle will move to the next intersection in the direction it is facing.
 * @return true if the vehicle was able to move forward, false otherwise
 */
bool Vehicle::drive()
{
    Intersection *nextLocation = nullptr; // The next location the vehicle will move to
    // Determine the next location based on the direction the vehicle is facing
    switch (direction)
    {
    case Direction::NORTH:
        nextLocation = location->getNorthNeighbor();
        break;
    case Direction::SOUTH:
        nextLocation = location->getSouthNeighbor();
        break;
    case Direction::EAST:
        nextLocation = location->getEastNeighbor();
        break;
    case Direction::WEST:
        nextLocation = location->getWestNeighbor();
        break;
    }

    // If the next location is not null, move the vehicle to the next location
    if (nextLocation)
    {
        location = nextLocation;
        return true; // The vehicle was able to move forward
    }
    return false; // The vehicle was not able to move forward
}
