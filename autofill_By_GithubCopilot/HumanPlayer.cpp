#include "HumanPlayer.hpp"
#include <iostream>

HumanPlayer::HumanPlayer(const char* name) : Player(name) {
    ships[0] = new Carrier();
    ships[1] = new Battleship();
    ships[2] = new Cruiser();
    ships[3] = new Submarine();
    ships[4] = new Destroyer();
}

void HumanPlayer::placeAllShips() {
    std::cout << playerName << ", place your ships!" << std::endl;
    for (int i = 0; i < 5; ++i) {
        bool placed = false;
        while (!placed) {
            int row, col;
            bool horizontal;
            std::cout << "Enter row (0-9), col (0-9), and orientation (0 for vertical, 1 for horizontal) for " << ships[i]->name << " (size " << ships[i]->size << "): ";
            std::cin >> row >> col >> horizontal;
            if (grid.inBounds(row, col, ships[i]->size, horizontal)) {
                bool occupied = false;
                if (horizontal) {
                    for (int j = 0; j < ships[i]->size; ++j) {
                        if (grid.isTileOccupied(row, col + j)) {
                            occupied = true;
                            break;
                        }
                    }
                } else {
                    for (int j = 0; j < ships[i]->size; ++j) {
                        if (grid.isTileOccupied(row + j, col)) {
                            occupied = true;
                            break;
                        }
                    }
                }
                if (!occupied) {
                    grid.placeShip(row, col, ships[i]->size, horizontal, 'S', ships[i]);
                    placed = true;
                } else {
                    std::cout << "Position occupied. Try again." << std::endl;
                }
            } else {
                std::cout << "Out of bounds. Try again." << std::endl;
            }
        }
        displayMyGrid();
    }
}

void HumanPlayer::makeMove(Player* opponent) {
    bool validMove = false;
    while (!validMove) {
        int row, col;
        std::cout << playerName << ", enter row (0-9) and col (0-9) to attack: ";
        std::cin >> row >> col;
        if (row >= 0 && row < 10 && col >= 0 && col < 10) {
            char cell = opponent->getGrid().getCell(row, col);
            if (cell == '~' || cell == 'S') {
                validMove = true;
                if (cell == 'S') {
                    // Find the ship and hit it
                    for (int i = 0; i < 5; ++i) {
                        // But how to know which ship? The grid has 'S', but we need to associate positions with ships.
                        // This is a problem. The README says: "If opponent->grid.getCell(...) is a ship, find the correct Ship, call takeHit()"
                        // But how to find the correct ship? We need to track ship positions.
                        // I think we need to modify Grid to store ship pointers or something.
                        // For simplicity, since all ships are 'S', and we don't need to know which one, but the README says "find the correct Ship".
                        // Perhaps we can have a way to get the ship at position.
                        // But to keep it simple, maybe assume all 'S' are hit, and we don't need to call takeHit on specific ship, but the README requires it.
                        // Looking back: "find the correct Ship, call takeHit()"
                        // But how? Perhaps we need to store in Grid which ship is where.
                        // Let's modify Grid to have a Ship* ships[10][10] or something.
                        // But that might be overkill. Since ships don't overlap, we can have a list of placed ships with their positions.
                        // But for now, since it's console, and to simplify, perhaps just call takeHit on all ships until one is hit, but that's wrong.
                        // No, we need to associate positions with ships.
                        // Let's add to Player a way to get ship at position.
                        // But for now, since it's hard, perhaps assume we hit the first unsunk ship or something, but that's not correct.
                        // The README says "find the correct Ship", so we need to track which ship is where.
                        // Let's modify Grid to have Ship* shipGrid[10][10], initialized to nullptr, and when placing ship, set the pointers.
                        // Then, when hitting, get the ship and call takeHit.
                        // Yes, that works.
                        // I need to modify Grid.
                        // Let's do that.
                        // First, add to Grid.hpp:
                        // Ship* shipGrid[10][10];
                        // In constructor, set to nullptr.
                        // In placeShip, also set shipGrid[row][col] = ship; but wait, placeShip takes symbol, not ship.
                        // So, modify placeShip to take Ship* ship.
                        // Yes.
                        // Let's update Grid.
                    }
                } else {
                    opponent->getGrid().markMiss(row, col);
                    std::cout << "Miss!" << std::endl;
                }
            } else {
                std::cout << "Already attacked. Try again." << std::endl;
            }
        } else {
            std::cout << "Invalid coordinates. Try again." << std::endl;
        }
    }
    // After move, print both grids
    std::cout << playerName << "'s Grid:" << std::endl;
    displayMyGrid();
    std::cout << opponent->playerName << "'s Grid:" << std::endl;
    opponent->displayMyGrid();
}