#include <iostream>
#include "Grid.hpp"
#include "HumanPlayer.hpp"
#include "Ship.hpp"
#include "Carrier.hpp"
#include "Battleship.hpp"
#include "Cruiser.hpp"
#include "Submarine.hpp"
#include "Destroyer.hpp"

void HumanPlayer::getInput(int &row, int &col, bool &orientation)
{
    char orientChar;
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
    std::cin >> orientChar;
    while (orientChar != 'H' && orientChar != 'h' && orientChar != 'V' && orientChar != 'v')
    {
        std::cout << "Invalid orientation. Try again." << std::endl;
        std::cin >> orientChar;
    }
    orientation = (orientChar == 'H' || orientChar == 'h');
}

void HumanPlayer::manuallyPlaceAShip(int length, char symbol)
{
    int row, col;
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
        bool horizontal;
        getInput(row, col, horizontal);
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
        //DEBUG
        // std::cout << "Placed ship at (" << row + 1 << ", " << col + 1 << ") "
        //           << (horizontal ? "horizontally." : "vertically.") << std::endl;
        //Debug
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

        switch (symbols[i])
        {
            case 'C': ships[i] = new Carrier(); break;
            case 'B': ships[i] = new Battleship(); break;
            case 'R': ships[i] = new Cruiser(); break;
            case 'S': ships[i] = new Submarine(); break;
            case 'D': ships[i] = new Destroyer(); break;
            default: ships[i] = nullptr; break;
    }

}
    std::cout << "All ships placed for " << playerName << "!" << std::endl;
}

void HumanPlayer::makeMove(Player *opponent)
{
    int row, col;
    std::cout << "\n" << playerName << ", it's your turn to make a move." << std::endl;

    opponent->getOcean().printGrid(false);

    std::cout << "enter target row (1-10): ";
    std::cin >> row;
    std::cout << "enter target column (1-10): ";
    std::cin >> col;

    row--; // Adjust for 0-based index
    col--; // Adjust for 0-based index

    char targetCell = opponent->getOcean().getCell(row, col);

    if (targetCell == 'X' || targetCell == 'M')
    {
        std::cout << "You have already targeted this cell. Try again." << std::endl;
        makeMove(opponent); // Retry move
        return;
    }

    if (targetCell == 'S' || targetCell == 'C' || targetCell == 'B' || targetCell == 'R' || targetCell == 'D')
    {
        std::cout << "It's a hit!" << std::endl;
        Ship* hitShip = opponent->getShipBySymbol(targetCell);
        hitShip->takeHit();
        opponent->getOcean().markHit(row, col);

        if (hitShip->isSunk())
        {
            std::cout << "You sunk " << opponent->getName() << "'s " << hitShip->getName() << "!" << std::endl;
        }
    }

    else
    {
        std::cout << "It's a miss." << std::endl;
        opponent->getOcean().markMiss(row, col);
    }

    std::cout << "\nyour grid:\n";
    ocean.printGrid(true);
    std::cout << "\nopponent's grid:\n";
    opponent->getOcean().printGrid(false);

    std::cout << "\n------------------------------\n";
    std::cout << "End of " << playerName << "'s turn." << std::endl;
    std::cout << "------------------------------\n";
}