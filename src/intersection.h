#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <string>

using namespace std;

class Intersection
{
private:
    string name;                 // The name of the intersection.
    Intersection *northNeighbor; // The intersection to the north.
    Intersection *eastNeighbor;  // The intersection to the east.
    Intersection *southNeighbor; // The intersection to the south.
    Intersection *westNeighbor;  // The intersection to the west.
    bool isBusStop;

public:
    // Constructor for an intersection.
    Intersection(string name = "", bool busStop = false);
    // Getter for the name of the intersection.
    string getName() const;
    Intersection *getNorthNeighbor() const;
    Intersection *getSouthNeighbor() const;
    Intersection *getEastNeighbor() const;
    Intersection *getWestNeighbor() const;
    bool getIsBusStop() const;
    // Setter for the name of the intersection.
    void setName(string newName);
    void setNorthNeighbor(Intersection *neighbor);
    void setSouthNeighbor(Intersection *neighbor);
    void setEastNeighbor(Intersection *neighbor);
    void setWestNeighbor(Intersection *neighbor);
    void setIsBusStop(bool busStop);
};

#endif
