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
