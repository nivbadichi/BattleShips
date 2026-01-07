#pragma once
#include "Ship.hpp"

class Battleship : public Ship {
public:
    Battleship() : Ship("Battleship", 4) {}
};