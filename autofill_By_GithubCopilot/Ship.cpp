#include "Ship.hpp"
#include <cstring>
#include <iostream>

Ship::Ship(const char* shipName, int shipSize) : size(shipSize), hitsTaken(0) {
    name = new char[strlen(shipName) + 1];
    strcpy(name, shipName);
}

Ship::~Ship() {
    delete[] name;
}

void Ship::takeHit() {
    hitsTaken++;
    std::cout << name << " got hit!" << std::endl;
    if (hitsTaken >= size) {
        std::cout << name << " is sunk!" << std::endl;
    }
}

bool Ship::isSunk() const {
    return hitsTaken >= size;
}