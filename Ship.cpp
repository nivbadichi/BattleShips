/*======================================
created by Alex Tkachenkov & Niv Badichi
  ======================================*/






#include "Ship.hpp"
#include <cstring>
#include <iostream>
using namespace std;

    Ship::Ship(const char *shipName, int shipSize)   // Initializes name and size.
    {
        size = shipSize;
        hitsTaken = 0;
        name = new char[strlen(shipName) + 1];
        strcpy(name, shipName);
    }


    Ship::~Ship()   // Cleans up allocated memory for name.
    {                            
        delete [] name;
    }

    void Ship::takeHit() // Increments hitsTaken by 1 and outputs a message indicating the ship got hit.
    {
        hitsTaken++;
        std::cout << name << " got hit!" << std::endl;
    }
    
    
    bool Ship::isSunk() const  // Returns true if hitsTaken >= size.
    {                       
    return hitsTaken >= size;
    }

    const char* Ship::getName() const {
        return name;
    }

    int Ship::getSize() const {
        return size;
    }

    int Ship::getHitsTaken() const {
        return hitsTaken;
    }

    