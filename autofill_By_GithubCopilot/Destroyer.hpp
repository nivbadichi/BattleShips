#pragma once
#include "Ship.hpp"

class Destroyer : public Ship {
public:
    Destroyer() : Ship("Destroyer", 2) {}
};