#pragma once
#include "Player.hpp"

class AiPlayer : public Player {
public:
    AiPlayer(const char* name);
    ~AiPlayer() override;

    void placeAllShips() override;
    void makeMove(Player* opponent) override;
private:
    int getRandomcoordinate() const;
    bool getRandomBoolean() const;
};