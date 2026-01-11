#pragma once
#include "Player.hpp"

class HumanPlayer : public Player {
public:
    HumanPlayer(const char* name);
    ~HumanPlayer() override;

    void placeAllShips() override;
    void makeMove(Player* opponent) override;
};