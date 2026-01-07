#include "Grid.hpp"
#include <iostream>

Grid::Grid() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cells[i][j] = '~';
            shipGrid[i][j] = nullptr;
        }
    }
}

bool Grid::isTileOccupied(int row, int col) const {
    return cells[row][col] == 'S' || cells[row][col] == 'X';
}

bool Grid::inBounds(int row, int col, int shipSize, bool horizontal) const {
    if (horizontal) {
        return col + shipSize <= 10;
    } else {
        return row + shipSize <= 10;
    }
}

void Grid::placeShip(int row, int col, int shipSize, bool horizontal, char symbol, Ship* ship) {
    if (horizontal) {
        for (int i = 0; i < shipSize; ++i) {
            cells[row][col + i] = symbol;
            shipGrid[row][col + i] = ship;
        }
    } else {
        for (int i = 0; i < shipSize; ++i) {
            cells[row + i][col] = symbol;
            shipGrid[row + i][col] = ship;
        }
    }
}

void Grid::markHit(int row, int col) {
    cells[row][col] = 'X';
}

void Grid::markMiss(int row, int col) {
    cells[row][col] = 'M';
}

char Grid::getCell(int row, int col) const {
    return cells[row][col];
}

Ship* Grid::getShip(int row, int col) const {
    return shipGrid[row][col];
}

void Grid::printGrid() const {
    std::cout << "  ";
    for (int j = 0; j < 10; ++j) {
        std::cout << j << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < 10; ++j) {
            std::cout << cells[i][j] << " ";
        }
        std::cout << std::endl;
    }
}