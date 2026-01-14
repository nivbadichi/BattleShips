#include "Player.hpp"
#include <cstring>
#include <iostream>
using namespace std;

Player::Player(const char *name)
{
    ships[0] = new Carrier();
    ships[1] = new Battleship();
    ships[2] = new Cruiser();
    ships[3] = new Submarine();
    ships[4] = new Destroyer();


    // const char* symbols[5] = {"C", "B", "R", "S", "D"};
    // const int sizes[5] = {5, 4, 3, 3, 2};
    // for (int i = 0; i < 5; ++i)
    // {
    //     // debug
    //     //std::cout << "IN PLAYER.CPP CONSTRUCTOR" << std::endl                  << "Creating ship: " << symbols[i] << " of size " << sizes[i] << std::endl;
    //     //
    //     ships[i] = new Ship(symbols[i], sizes[i]);
    // }
    playerName = new char[strlen(name) + 1];
    strcpy(playerName, name);
}

Player::~Player()
{
    delete[] playerName;

    for (int i = 0; i < 5; ++i)
    {
        delete ships[i];
    }
}

bool Player::allShipsSunk() const
{
    // debug
    //std::cout << "IN PLAYER,CPP allShipsSunk():" << std::endl << "checking ships status..."<<std::endl;
    //
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

bool Player::IsCharShip(const char &Ship)
{
    if (Ship == 'C' || Ship == 'c' || Ship == 'B' || Ship == 'b' || Ship == 'R' || Ship == 'r' || Ship == 'S' || Ship == 's' || Ship == 'D' || Ship == 'd')
    {
        return true;
    }
    else
    {
        return false;
    }
}

const char *Player::getName() const
{
    return playerName;
}

Ship *Player::getShipBySymbol(char symbol)
{
    // debug
    //std::cout << "Getting ship for symbol: " << symbol << std::endl;
    //
    switch (symbol)
    {
    case 'C':
        return ships[0]; // Carrier
    case 'c':
        return ships[0]; // Carrier
    case 'B':
        return ships[1]; // Battleship
    case 'b':
        return ships[1]; // Battleship
    case 'R':
        return ships[2]; // Cruiser
    case 'r':
        return ships[2]; // Cruiser
    case 'S':
        return ships[3]; // Submarine
    case 's':
        return ships[3]; // Submarine
    case 'D':
        return ships[4]; // Destroyer
    case 'd':
        return ships[4]; // Destroyer
    default:
        return nullptr; // No ship corresponds to this symbol
    }
}

Grid &Player::getOcean()
{
    return ocean;
}

Grid &Player::getTarget()
{
    return target;
}
