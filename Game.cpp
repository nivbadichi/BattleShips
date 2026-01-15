<<<<<<< HEAD
/*======================================
created by Alex Tkachenkov & Niv Badichi
  ======================================*/






#include "Game.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.hpp"
#include "Grid.hpp"
#include "Ship.hpp"
#include <chrono>
#include <thread>
#define SLEEP_DURATION 4000 // milliseconds
#define DelayMode true
#define SLEEP std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_DURATION));
using namespace std;

Game::Game(Player* p1, Player* p2) : player1(p1), player2(p2) {} // Constructor to initialize players


void Game::setup() {
    // Each player places all their ships
    player1->placeAllShips();
    player2->placeAllShips();
}


bool Game::isGameOver() const {
    // The game is over if either player has all their ships sunk
    return player1->allShipsSunk() || player2->allShipsSunk();
}


void Game::start() {
    cout <<"==== The Battle Begins! ====" << endl;
    if (DelayMode) SLEEP

    while (!isGameOver()) {

        cout << "\n==============================\n";
        cout << "    " << player1->getName() << "'s Turn\n";
        cout << "\n==============================\n";
        if (DelayMode) SLEEP

        player1->makeMove(player2);
        if (DelayMode) SLEEP

        if (isGameOver())
            break;
        
        cout << "\n==============================\n";
        cout << "    " << player2->getName() << "'s Turn\n";
        cout << "\n==============================\n";
        if (DelayMode) SLEEP

        player2->makeMove(player1);
        if (DelayMode) SLEEP
    }   
        if (DelayMode) SLEEP   
        if (player1->allShipsSunk()) {
            cout << "\n*** " << player2->getName() << " Wins! ***" << endl;
        } else if (player2->allShipsSunk()) {
            cout << "\n*** " << player1->getName() << " Wins! ***" << endl;
        }
    }
=======
#include "player.hpp"
#include "Game.hpp"
#include <iostream>

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
    std::cout <<"IN GAME.CPP isGameOver():"<<std::endl<< "Checking if game is over on HUMAN"<<std::endl;
    //
    if (player2->allShipsSunk())
    {
        std::cout << player1->getName() << " has sunken all of " << player2->getName() << "'s ships!" << std::endl;
        return true;
    }
    // debug
    std::cout <<"IN GAME.CPP isGameOver():"<<std::endl<< "Checking if game is over on AI"<<std::endl;
    //
    if (player1->allShipsSunk())
    {
        std::cout << player2->getName() << " has sunken all of " << player1->getName() << "'s ships!" << std::endl;
        return true;
    }
    return false;
};
>>>>>>> origin/main
