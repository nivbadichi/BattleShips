#pragma once
#include "Player.hpp"
#include "Carrier.hpp"
#include "Battleship.hpp"
#include "Cruiser.hpp"
#include "Submarine.hpp"
#include "Destroyer.hpp"

class HumanPlayer : public Player {
public:
    HumanPlayer(const char* name);
    void placeAllShips() override;
    void makeMove(Player* opponent) override;
};