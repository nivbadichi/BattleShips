#pragma once
#include "Player.hpp"

class HumanPlayer : public Player {
public:
    HumanPlayer(const char* name) : Player(name) {}
    void manuallyPlaceAShip(int length, char symbol);
    void placeAllShips() override;
    void makeMove(Player* opponent) override;
    void getInput(int &row, int &col, bool &orientation);
};
