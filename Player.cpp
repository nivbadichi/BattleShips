#include "Player.hpp"
#include <cstring>
#include <iostream>
using namespace std;


Player::Player(const char* name) {
    
    playerName = new char[strlen(name) + 1];
    strcpy(playerName, name);

    for (int i = 0; i < 5; ++i) {
        ships[i] = nullptr;
    }
}


Player::~Player() {
    delete[] playerName;

    for (int i = 0; i < 5; ++i) {
        delete ships[i];
    }
}

bool Player::allShipsSunk() const
{
    for (int i = 0; i < 5; i++)
    {
        if (ships[i] == nullptr)
        {
            return false;
        }

        if (!ships[i]->isSunk())
        {
            return false;
        }
    }

    return true;
}

const char* Player::getName() const {
    return playerName;
}

Grid& Player::getOcean() {
    return ocean;
}

Grid& Player::getTarget() {
    return target;
}

