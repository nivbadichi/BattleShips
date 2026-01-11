#include <iostream>
#include "Grid.hpp"
#include "HumanPlayer.hpp"

void HumanPlayer::getInput(int &row, int &col, bool &orientation)
{
    std::cout << "Enter row (1-10): ";
    std::cin >> row;
    while (row < 1 || row > 10)
    {
        std::cout << "Invalid row. Try again." << std::endl;
        std::cin >> row;
    }
    row--; // Adjust for 0-based index
    std::cout << "Enter column (1-10): ";
    std::cin >> col;
    while (col < 1 || col > 10)
    {
        std::cout << "Invalid column. Try again." << std::endl;
        std::cin >> col;
    }
    col--; // Adjust for 0-based index
    std::cout << "Enter orientation (H for horizontal, V for vertical): ";
    std::cin >> orientation;
    while (orientation != 'H' && orientation != 'h' && orientation != 'V' && orientation != 'v')
    {
        std::cout << "Invalid orientation. Try again." << std::endl;
        std::cin >> orientation;
    }
    orientation = (orientChar == 'H' || orientChar == 'h');
}

void HumanPlayer::manuallyPlaceAShip(int length, char symbol)
{
    int row, col;
    char orientation;
    bool placed = false;
    std::cout << "choose where to place";
    switch (length)
    {
    case 5:
        std::cout << " Carrier (length 5)" << std::endl;
        break;
    case 4:
        std::cout << " Battleship (length 4)" << std::endl;
        break;
    case 3:
        std::cout << " Cruiser (length 3)" << std::endl;
        break;
    case 2:
        std::cout << " Destroyer (length 2)" << std::endl;
        break;
    default:
        std::cout << " Ship (length " << length << ")" << std::endl;
        break;
    }

    while (!placed)
    {
        getInput(row, col, orientation);
        bool horizontal = (orientation == 'H' || orientation == 'h');
        if (!ocean.inBounds(row, col, length, horizontal))
        {
            std::cout << "Ship does not fit in the grid at that position. Try again." << std::endl;
            continue;
        }

        if (!ocean.validatePlacement(row, col, length, horizontal))
        {
            std::cout << "Ship overlaps with another ship. Try again." << std::endl;
            continue;
        }
        ocean.placeShip(row, col, length, horizontal, symbol);
        placed = true;
        ocean.printGrid(true);
    }
}

void HumanPlayer::placeAllShips()
{
    std::cout << "Player " << playerName << ", place your ships on the grid." << std::endl;
    const char symbols[5] = {'C', 'B', 'R', 'S', 'D'};
    const int sizes[5] = {5, 4, 3, 3, 2};
    for (int i = 0; i < 5; ++i)
    {
        manuallyPlaceAShip(sizes[i], symbols[i]);
    }
}

void HumanPlayer::makeMove(Player *opponent)
{
    opponent->getOcean().printGrid(false);
}