#pragma once
#include "Ship.hpp"

class Submarine : public Ship {
public:
    Submarine() : Ship("Submarine", 3) {}
};