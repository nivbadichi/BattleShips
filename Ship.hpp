<<<<<<< HEAD
/*======================================
created by Alex Tkachenkov & Niv Badichi
  ======================================*/






#pragma once
class Ship
{
private:
    char *name;
    int size;
    int hitsTaken;

    Ship(const Ship &other) = delete; // Disable copy constructor
    Ship &operator=(const Ship &other) = delete; // Disable copy assignment operator

public:
    // Constructor and Destructor
    Ship(const char *shipName, int shipSize);   // Initializes name and size.
    virtual ~Ship();                            // Cleans up allocated memory for name.
    
    // Getters
    const char* getName() const;
    int getSize() const;
    int getHitsTaken() const;

    // Member Functions
    virtual void takeHit();                     // Increments hitsTaken and prints "<ShipName> got hit!".also Checks if hitsTaken >= size.                                         
    bool isSunk() const;                        // Returns true if hitsTaken >= size.
=======
#pragma once

//in this project, possible ships:
// C||c Carrier (size = 5)
// B||b Battleship (size = 4)
// R||r Cruiser (size = 3)
// S||s Submarine (size = 3)
// D||d Destroyer (size = 2)

class Ship
{
private:
    char *name;
    int size;
    int hitsTaken;

    Ship(const Ship &other) = delete; // Disable copy constructor
    Ship &operator=(const Ship &other) = delete; // Disable copy assignment operator

public:
    // Constructor and Destructor
    Ship(const char *shipName, int shipSize);   // Initializes name and size.
    virtual ~Ship();                            // Cleans up allocated memory for name.
    
    // Getters
    const char* getName() const;
    int getSize() const;
    int getHitsTaken() const;

    // Member Functions
    virtual void takeHit();                     // Increments hitsTaken and prints "<ShipName> got hit!".also Checks if hitsTaken >= size.                                         
    bool isSunk() const;                        // Returns true if hitsTaken >= size.
>>>>>>> origin/main
};