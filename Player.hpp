#pragma once
#include "Ship.hpp"
#include "Battleship.hpp"
#include "Carrier.hpp"
#include "Cruiser.hpp"
#include "Destroyer.hpp"
#include "Submarine.hpp"
#include "Grid.hpp"

class Player {
    protected:
        char* playerName;

        Ship* ships[5]; // Array to hold 5 ships
        Grid ocean; // Player's own grid with ships
        Grid target; // Grid to track shots on opponent
    
    public:
        Player(const char* name); // Constructor to initialize playerName and ships
        virtual ~Player(); // Destructor to clean up allocated memory

        virtual void placeAllShips() = 0; // Pure virtual function for placing ships
        virtual void makeMove(Player* opponent) = 0; // Pure virtual function for taking a turn

        bool allShipsSunk() const; // Returns true if all ships are sunk
        bool IsCharShip(const char& Ship);
        // getters
        const char* getName() const; // Returns playerName
        Ship* getShipBySymbol(char symbol); // Returns pointer to ship based on symbol
        Grid& getOcean(); // Returns reference to ocean grid
        Grid& getTarget(); // Returns reference to target grid

};