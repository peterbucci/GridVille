#include "Intersection.h"

/**
 * Constructor for an intersection.
 * @param name the name of the intersection
 * @param busStop whether the intersection is a bus stop
 */
Intersection::Intersection(string name, bool busStop)
    : name(name), northNeighbor(nullptr), southNeighbor(nullptr),
      eastNeighbor(nullptr), westNeighbor(nullptr), isBusStop(busStop) {}

/**
 * Getter for the name of the intersection.
 * @return the name of the intersection
 */
string Intersection::getName() const
{
    return name;
}

/**
 * Getter for the intersection to the north.
 * @return the intersection to the north
 */
Intersection *Intersection::getNorthNeighbor() const
{
    return northNeighbor;
}

/**
 * Getter for the intersection to the south.
 * @return the intersection to the south
 */
Intersection *Intersection::getSouthNeighbor() const
{
    return southNeighbor;
}

/**
 * Getter for the intersection to the east.
 * @return the intersection to the east
 */
Intersection *Intersection::getEastNeighbor() const
{
    return eastNeighbor;
}

/**
 * Getter for the intersection to the west.
 * @return the intersection to the west
 */
Intersection *Intersection::getWestNeighbor() const
{
    return westNeighbor;
}

/**
 * Getter for whether the intersection is a bus stop.
 * @return whether the intersection is a bus stop
 */
bool Intersection::getIsBusStop() const
{
    return isBusStop;
}

/**
 * Setter for the name of the intersection.
 * @param newName the new name of the intersection
 */
void Intersection::setName(string newName)
{
    name = newName;
}

/**
 * Setter for the intersection to the north.
 * Also sets this intersection as the south neighbor of the new intersection.
 * @param neighbor the new intersection to the north
 */
void Intersection::setNorthNeighbor(Intersection *neighbor)
{
    northNeighbor = neighbor;
    if (neighbor)
        neighbor->southNeighbor = this;
}

/**
 * Setter for the intersection to the south.
 * Also sets this intersection as the north neighbor of the new intersection.
 * @param neighbor the new intersection to the south
 */
void Intersection::setSouthNeighbor(Intersection *neighbor)
{
    southNeighbor = neighbor;
    if (neighbor)
        neighbor->northNeighbor = this;
}

/**
 * Setter for the intersection to the east.
 * Also sets this intersection as the west neighbor of the new intersection.
 * @param neighbor the new intersection to the east
 */
void Intersection::setEastNeighbor(Intersection *neighbor)
{
    eastNeighbor = neighbor;
    if (neighbor)
        neighbor->westNeighbor = this;
}

/**
 * Setter for the intersection to the west.
 * Also sets this intersection as the east neighbor of the new intersection.
 * @param neighbor the new intersection to the west
 */
void Intersection::setWestNeighbor(Intersection *neighbor)
{
    westNeighbor = neighbor;
    if (neighbor)
        neighbor->eastNeighbor = this;
}

/**
 * Setter for whether the intersection is a bus stop.
 * @param busStop whether the intersection is a bus stop
 */
void Intersection::setIsBusStop(bool busStop)
{
    isBusStop = busStop;
}