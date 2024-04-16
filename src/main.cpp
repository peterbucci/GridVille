/**
 * @title: Gridville
 * @version: 2.0
 * @date: 2024-04-08
 * @description: This program simulates a vehicle moving through a grid of intersections in Gridville.
 * The vehicle will move in a snake-like pattern, turning south when it reaches a dead end.
 * The vehicle will stop at bus stops if it's a bus. The tour is complete when the vehicle can't move south anymore.
 * @notes: The avanues and streets are read from files located in the res folder. Adjust the paths if needed.
 */

#include <cstdio>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "intersection.h"
#include "Car.h"
#include "Bus.h"

using namespace std;

// Global variables for avenues and streets
vector<string> g_avenues; // This is the list of avenues
vector<string> g_streets; // This is the list of streets

// Function to load a vector of strings from a file.
vector<string> loadFromFile(const string &fileName);

// Function to print a vector of strings.
void printVectorOfStrings(const vector<string> &v);

// Function to build the gridville. It creates a grid of intersections with random bus stops.
vector<vector<Intersection>> buildGridville();

// Function to perform the grand tour with a vehicle starting at a given intersection.
void grandTour(Vehicle &vehicle, Intersection *start);

int main()
{
  // Get the streets and avenues from files
  g_streets = loadFromFile("../../res/streets.txt"); // Adjust the path if needed
  g_avenues = loadFromFile("../../res/avenues.txt"); // Adjust the path if needed

  cout << "The streets are: " << endl;
  printVectorOfStrings(g_streets);
  cout << "The avenues are: " << endl;
  printVectorOfStrings(g_avenues);

  auto grid = buildGridville();

  Car car = Car("Car", &grid[0][0], Direction::EAST); // Place the car at the top-left corner facing east
  Bus bus = Bus("Bus", &grid[0][0], Direction::EAST); // Place the bus at the top-left corner facing east

  cout << endl
       << "----------------------------------------" << endl;
  cout << "Starting the grand tour with the car." << endl;
  cout << "----------------------------------------" << endl
       << endl;
  grandTour(car, &grid[0][0]); // Start the grand tour with the car at the top-left corner

  cout << endl
       << "----------------------------------------" << endl;
  cout << "Starting the grand tour with the bus." << endl;
  cout << "----------------------------------------" << endl
       << endl;
  grandTour(bus, &grid[0][0]); // Start the grand tour with the bus at the top-left corner

  return 0;
}

/**
 * The loadFromFile function takes as argument a string containing a filename. It
 * creates a vector of strings and reads from the file, putting each line of the
 * file into one element of the vector, skipping blank lines. Finally it returns the
 * vector.
 * @param fileName the name of the file to read from
 * @return a vector of strings containing the lines read from the file
 */
vector<string> loadFromFile(const string &fileName)
{

  // set up a file stream and open it for reading
  ifstream file;
  file.open(fileName);

  // Create a new vector of strings
  vector<string> result;

  if (file)
  {
    // While the input file still has strings to be read (i.e. not at end of
    // file), read a line from the file. If the line is not blank, then add it to
    // result. (hint: a blank line is a string of length 0)
    string line;
    while (getline(file, line))
    {
      if (line.length() > 0)
      {
        result.push_back(line);
      }
    }

    // Program 12.8 from the Gaddis book will help you here
    file.close();
  }
  else
  {
    cout << "Error: could not open file " << fileName << endl;
  }

  return result;
}

/**
 * printVectorOfsStrings prints out a vector of strings, with one string per line.
 * @param v the vector of strings to print
 */
void printVectorOfStrings(const vector<string> &v)
{
  for (int i = 0; i < v.size(); i++)
  {
    cout << "[" << i << "]: " << v[i] << endl;
  }
}

/**
 * Function to build the gridville. It creates a grid of intersections with random bus stops.
 * @return a 2D vector of intersections
 */
vector<vector<Intersection>> buildGridville()
{
  srand(time(nullptr)); // Seed for random bus stop generation
  int gridHeight = g_streets.size();
  int gridWidth = g_avenues.size();

  // Create a grid of intersections
  vector<vector<Intersection>> grid(gridHeight, vector<Intersection>(gridWidth));

  // Initialize intersections
  for (int i = 0; i < gridHeight; ++i) // Holds the streets
  {
    for (int j = 0; j < gridWidth; ++j) // Holds the avenues
    {
      string name = g_streets[i] + " & " + g_avenues[j]; // Intersection name
      grid[i][j] = Intersection(name, rand() % 100 < 9); // ~9% chance to be a bus stop
    }
  }

  /*
   * Traverse the grid to set the neighbors of each intersection.
   * North and west neighbors are set inside the setNorthNeighbor and setWestNeighbor methods.
   */
  for (int i = 0; i < gridHeight; ++i) // Traverse the streets
  {
    for (int j = 0; j < gridWidth; ++j) // Traverse the avenues
    {
      if (i < gridHeight - 1) // If not the last street
        grid[i][j].setSouthNeighbor(&grid[i + 1][j]);
      if (j < gridWidth - 1) // If not the last avenue
        grid[i][j].setEastNeighbor(&grid[i][j + 1]);
    }
  }

  return grid;
}

/**
 * Function to perform the grand tour with a vehicle starting at a given intersection.
 * The vehicle will move through the gridville in a snake-like pattern, turning south when it reaches a dead end.
 * The vehicle will stop at bus stops if it's a bus. The tour is complete when the vehicle can't move south anymore.
 * @param vehicle the vehicle to perform the grand tour
 * @param start the intersection where the vehicle starts
 */
void grandTour(Vehicle &vehicle, Intersection *start)
{
  vehicle.setLocation(start);            // Start at the given intersection
  vehicle.setDirection(Direction::EAST); // Start by moving east

  bool goingEast = true; // To keep track of the horizontal direction

  /*
   * The grand tour is a loop that keeps moving the vehicle forward until it can't move anymore.
   * When the vehicle can't move forward, it turns south and tries to move forward again.
   * If it can't move south either, the tour is complete.
   */
  while (true)
  {
    // Print the current state of the vehicle
    cout << "At intersection: " << vehicle.getLocation()->getName()
         << " facing " << vehicle.getDirection() << " in a " << vehicle.getName() << (vehicle.getLocation()->getIsBusStop() ? " at a bus stop." : "");

    // Check if the vehicle can stop at the current intersection
    if (vehicle.canStopHere(vehicle.getLocation()))
    {
      cout << " - Stopping here." << endl;
    }
    else
    {
      cout << " - Can't stop here." << endl;
    }

    // Try moving forward. If the vehicle can't move forward, it will turn south.
    if (!vehicle.drive())
    {
      cout << "Can't move " << (goingEast ? "east" : "west") << " turning south." << endl;

      // Can't move forward; try turning south
      vehicle.setDirection(Direction::SOUTH);

      // Try moving south. If the vehicle can't move south, the tour is complete.
      if (!vehicle.drive())
      {
        cout << "Can't move south either. Tour complete." << endl;
        // Can't move south, the tour is complete
        break;
      }

      // After moving south, switch horizontal direction
      goingEast = !goingEast;
      vehicle.setDirection(goingEast ? Direction::EAST : Direction::WEST);
    }
  }
}
