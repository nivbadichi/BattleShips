#include <iostream>
#include "Grid.hpp"
using namespace std;

Grid::Grid()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cells[i][j] = '~'; // Initialize all cells to water symbol
        }
    }
}

bool Grid::isTileOccupied(int row, int col) const
{
    return cells[row][col] != '~';
}


bool Grid::inBounds(int row, int col, int shipSize, bool horizontal) const // Checks if placing a ship of length shipSize at (row, col) horizontally/vertically stays within the 10×10 grid.
{
    if (row < 0 || row >= 10 || col < 0 || col >= 10)
    {
        return false; // Out of bounds
    }
    if (horizontal)
    {
        if (col + shipSize > 10)
        {
            return false; // Ship would go out of bounds horizontally
        }
    }
    else
    {
        if (row + shipSize > 10)
        {
            return false; // Ship would go out of bounds vertically
        }
    }
    return true;
}

bool Grid::validatePlacement(int row, int col, int shipSize, bool horizontal)
{
    bool inBounds = this->inBounds(row, col, shipSize, horizontal);
    bool occupied = false;
    for (int i = 0; i < shipSize; i++)
    {
        if (horizontal)
        {
            if (this->isTileOccupied(row, col + i))
            {
                occupied = true;
                break;
            }
        }
        else
        {
            if (this->isTileOccupied(row + i, col))
            {
                occupied = true;
                break;
            }
        }
    }
    
    if (inBounds&&!occupied)
    return true;
    else
    return false;
}

void Grid::placeShip(int row, int col, int shipSize, bool horizontal, char symbol) // Marks each relevant cell with symbol (e.g., 'S') if valid.
{
    if (horizontal)
    {
        for (int j = 0; j < shipSize; j++)
        {
            cells[row][col + j] = symbol;
        }
    }
    else
    {
        for (int i = 0; i < shipSize; i++)
        {
            cells[row + i][col] = symbol;
        }
    } 
}

void Grid::markHit(int row, int col)                                               // Marks cells[row][col] as 'X'.
{
    cells[row][col] = 'X';
}

void Grid::markMiss(int row, int col)                                              // Marks cells[row][col] as 'M'.
{
    cells[row][col] = 'M';
}

char Grid::getCell(int row, int col) const                                         // Returns cells[row][col].
{
    return cells[row][col];
}

void Grid::printGrid(bool revealShips) const
{
    cout << "   ";
    for (int col = 0; col < 10; col++)
    {
        cout << col+1 << " ";
    }
    cout << endl;

    for (int row = 0; row < 10; row++)
    {
        cout << row+1 << "  ";

        for (int col = 0; col < 10; col++)
        {
            char cell = cells[row][col];

            if (!revealShips)
            {
                if (cell == 'C' || cell == 'B' || cell == 'R' || cell == 'S' || cell == 'D')
                {
                    cout << "~ ";
                }

                else cout << cell << " ";
            }

            else cout << cell << " ";
        }

        cout << endl;
    }
}
