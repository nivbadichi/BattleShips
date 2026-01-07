#include "Player.hpp"
#include <cstring>
#include <iostream>

Player::Player(const char* name) : grid() {
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

bool Player::allShipsSunk() const {
    for (int i = 0; i < 5; ++i) {
        if (ships[i] && !ships[i]->isSunk()) {
            return false;
        }
    }
    return true;
}

void Player::displayMyGrid() const {
    std::cout << playerName << "'s Grid:" << std::endl;
    grid.printGrid();
}

Grid& Player::getGrid() {
    return grid;
}