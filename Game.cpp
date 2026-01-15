/*======================================
created by Alex Tkachenkov & Niv Badichi
  ======================================*/

#include "player.hpp"
#include "Game.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#define SLEEP std::this_thread::sleep_for(std::chrono::milliseconds(4000));
#define DelayMode true


Game::Game(Player *p1, Player *p2) // Assigns two player objects (e.g., HumanPlayer vs. AiPlayer).
{
    player1 = p1;
    player2 = p2;
}
Game::~Game() // Cleans up allocated memory for player1 and player2.
{
    delete player1;
    delete player2;
}
void Game::setup() // Calls player1->placeAllShips();, then player2->placeAllShips();.
{
    player1->placeAllShips();
    player2->placeAllShips();
}
void Game::start() // Loop until one side is fully sunk:
{
    while (!isGameOver())
    {
        player1->makeMove(player2);
        if (isGameOver())
        break;
        player2->makeMove(player1);
        if (isGameOver())
        break;
    }
}

bool Game::isGameOver() const // Returns true if player1->allShipsSunk() or player2->allShipsSunk().
{
    // debug
    //std::cout <<"IN GAME.CPP isGameOver():"<<std::endl<< "Checking if game is over on HUMAN"<<std::endl;
    //
    if (player2->allShipsSunk())
    {
        if (DelayMode) SLEEP
        std::cout << player1->getName() << " has sunken all of " << player2->getName() << "'s ships!" << std::endl;
        return true;
    }
    // debug
    //std::cout <<"IN GAME.CPP isGameOver():"<<std::endl<< "Checking if game is over on AI"<<std::endl;
    //
    if (player1->allShipsSunk())
    {
        if (DelayMode) SLEEP
        std::cout << player2->getName() << " has sunken all of " << player1->getName() << "'s ships!" << std::endl;
        return true;
    }
    return false;
};
