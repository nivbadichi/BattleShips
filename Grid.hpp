#pragma once

class Grid
{
private:
    char cells[10][10]; // 10x10 grid
public:
    Grid();
    bool isTileOccupied(int row, int col) const;                          // Returns true if the cell indicates a ship or a previously hit cell.
    bool inBounds(int row, int col, int shipSize, bool horizontal) const; // Checks if placing a ship of length shipSize at (row, col) horizontally/vertically stays within the 10×10 grid.
    bool validatePlacement(int row, int col, int shipSize, bool horizontal);
    void placeShip(int row, int col, int shipSize, bool horizontal, char symbol); // Marks each relevant cell with symbol (e.g., 'S') if valid.
    void markHit(int row, int col);                                               // Marks cells[row][col] as 'X'.
    void markMiss(int row, int col);                                              // Marks cells[row][col] as 'M'.
    char getCell(int row, int col) const;                                         // Returns cells[row][col].
    void printGrid(bool revealShips) const;                                       // display the current state of cells. //Optional, not strictly required.
};