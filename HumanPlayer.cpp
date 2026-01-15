/*======================================
created by Alex Tkachenkov & Niv Badichi
  ======================================*/

#include <iostream>
#include <limits> // Required for numeric_limits
#include "Grid.hpp"
#include "HumanPlayer.hpp"
#include <chrono>
#include <thread>
#define SLEEP std::this_thread::sleep_for(std::chrono::milliseconds(4000));
#define DelayMode true
using namespace std;

void HumanPlayer::getInput(int &row, int &col) // save to 0 based index
{
    std::cout << "Enter row (1-10): ";
    std::cin >> row;
    while (std::cin.fail() || row < 1 || row > 10)
    {
        std::cout << "Invalid row. Try again." << std::endl;
        // 1. Fix the stream
        std::cin.clear();

        // 2. Ignore the rest of the current line (up to \n)
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cin >> row;
    }
    row--; // Adjust for 0-based index
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter column (1-10): ";
    std::cin >> col;
    while (std::cin.fail() || col < 1 || col > 10)
    {
        std::cout << "Invalid column. Try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> col;
    }
    col--; // Adjust for 0-based index
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return;
}

void HumanPlayer::getInputForShipPlacement(int &row, int &col, bool &orientation)
{
    char orientChar;
    getInput(row, col);
    std::cout << "Enter orientation (H for horizontal, V for vertical): ";
    std::cin >> orientChar;
    while (orientChar != 'H' && orientChar != 'h' && orientChar != 'V' && orientChar != 'v')
    {
        std::cout << "Invalid orientation. Try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> orientChar;
    }
    orientation = (orientChar == 'H' || orientChar == 'h');
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void HumanPlayer::manuallyPlaceAShip(int length, const char *symbol)
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
        getInputForShipPlacement(row, col, horizontal);
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
        ocean.placeShip(row, col, length, horizontal, symbol[0]);
        placed = true;
        ocean.printGrid(true);
        // DEBUG
        //  std::cout << "Placed ship at (" << row + 1 << ", " << col + 1 << ") "
        //            << (horizontal ? "horizontally." : "vertically.") << std::endl;
        // Debug
    }
}

void HumanPlayer::placeAllShips()
{
    std::cout << "Player " << playerName << ", place your ships on the grid." << std::endl;
    if (DelayMode) SLEEP
    const char *symbols[5] = {"C", "B", "R", "S", "D"};
    const int sizes[5] = {5, 4, 3, 3, 2};
    for (int i = 0; i < 5; ++i)
    {
        manuallyPlaceAShip(sizes[i], symbols[i]);
    }
}

void HumanPlayer::makeMove(Player *opponent)
{
    int row, col;
    std::cout << "<------------------------------------------->" << std::endl;
    std::cout << playerName << ", it's your turn to make a move." << std::endl
              << "Here's what you know:" << std::endl;
    target.printGrid(true);
    if (DelayMode) SLEEP
    getInput(row, col);
    while (target.isTileOccupied(row, col))
    {
        std::cout << "You have already fired at this location. Choose again." << std::endl;
        if (DelayMode) SLEEP
        getInput(row, col);
    }
    char result = opponent->getOcean().getCell(row, col);
    // debug
    //std::cout <<"IN HUMANPLAYER.CPP makeMove():"<<std::endl<< "You fired at (" << row + 1 << ", " << col + 1 << ") and got '" << result << "'." << std::endl;
    //
    //if (DelayMode) SLEEP
    // check if there was a ship
    if (IsCharShip(result))
    {
        target.markHit(row, col);
        std::cout << "Direct hit, Cap'n!" << std::endl;
        if (DelayMode) SLEEP
        opponent->getOcean().markHit(row, col);
        Ship *hitShip = opponent->getShipBySymbol(result); // currently leads to segfault
        // debug
        //std::cout << "You hit opponent's " << hitShip->getName() << "!" << std::endl;
        //
        if (hitShip)
        {
            hitShip->takeHit();
            // if we want to print that the ship was sunk
            //
            if (hitShip->isSunk())
            {
                std::cout << "Ship sunk!" << std::endl;
                if (DelayMode) SLEEP
            }
            //
        }
    }
    else
    {
        target.markMiss(row, col);
        opponent->getOcean().markMiss(row, col);
        std::cout << "Shot wide!" << std::endl
                  << "You missed!" << std::endl;
    }
    std::cout << "Updated target grid:" << std::endl;
    target.printGrid(true);
    std::cout << "Your Current grid:" << std::endl;
    ocean.printGrid(true);
    //std::cout << "<------------------------------------------->" << std::endl;
}