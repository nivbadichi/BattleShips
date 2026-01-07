#pragma once
#include "Ship.hpp"

class Cruiser : public Ship {
public:
    Cruiser() : Ship("Cruiser", 3) {}
};