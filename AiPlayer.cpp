/*======================================
created by Alex Tkachenkov & Niv Badichi
  ======================================*/






#include "AiPlayer.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
#include <chrono>
#include <thread>
#define SLEEP_DURATION 4000 // milliseconds
#define DelayMode true
#define SLEEP std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_DURATION));



AiPlayer::AiPlayer(const char* name) : Player(name) {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed for randomness
}

AiPlayer::~AiPlayer() {
}


int AiPlayer::getRandomcoordinate() const {
    return std::rand() % 10; // Random coordinate between 0 and 9
}

bool AiPlayer::getRandomBoolean() const {
    return std::rand() % 2 == 1; // Random boolean value
}


void AiPlayer::placeAllShips() {
    const char symbols[5] = {'C', 'B', 'R', 'S', 'D'};
    const int sizes[5] = {5, 4, 3, 3, 2};

    for (int i = 0; i < 5; ++i) {
        bool placed = false;
        while (!placed) {
            int row = getRandomcoordinate();
            int col = getRandomcoordinate();
            bool horizontal = getRandomBoolean();

            if (!ocean.inBounds(row,col, sizes[i], horizontal))
                continue;
            
            bool overlap = false;

            for (int k = 0; k < sizes[i]; ++k) {
                int r = horizontal ? 0 : k;
                int c = horizontal ? k : 0;
                if (ocean.isTileOccupied(r,c)) {
                    overlap = true;
                    break;
                }
            }
            if (!overlap) {
                ocean.placeShip(row, col, sizes[i], horizontal, symbols[i]);
                placed = true;
            }
        }
    }
}


void AiPlayer::makeMove(Player* opponent) {
    bool validShot = false;
    int row, col;

    if (DelayMode) {
        std::cout << "Ai is making its move..." << std::endl;
        SLEEP
    }

    while (!validShot) {
        row = getRandomcoordinate();
        col = getRandomcoordinate();

        char targetCell = target.getCell(row, col);
        if (targetCell == 'X' || targetCell == 'M') {
            continue; // Already shot here
        }

        validShot = true;
    }

    if (DelayMode) {
        std::cout << "Ai targets (" << row << ", " << col << ")." << std::endl;
        SLEEP
    }

    char opponentCell = opponent->getOcean().getCell(row, col);

    if (opponentCell == 'C' || opponentCell == 'B' || opponentCell == 'R' || opponentCell == 'S' || opponentCell == 'D') {
        opponent->getOcean().markHit(row, col);
        target.markHit(row, col);
        Ship* hitShip = opponent->getShipBySymbol(opponentCell);
        if (hitShip) {
            hitShip->takeHit();

            if (DelayMode) {
                std::cout << "Ai scored a hit!" << std::endl;
                SLEEP
            }
            if (hitShip->isSunk()) {
                std::cout << "Ai has sunk your " << hitShip->getName() << "!" << std::endl;
                if (DelayMode) SLEEP
            }
        }
    }
    else {
        opponent->getOcean().markMiss(row, col);
        target.markMiss(row, col);
        std::cout << "Ai missed at (" << row << ", " << col << ")." << std::endl;
        if (DelayMode) SLEEP
    }
}