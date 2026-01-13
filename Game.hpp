/*======================================
created by Alex Tkachenkov & Niv Badichi
  ======================================*/






#pragma once
#include "Player.hpp"

class Game {
    private:
        Player* player1;
        Player* player2;
    
    public:
        Game(Player* p1, Player* p2); // Constructor to initialize players

        void setup(); // Method to set up the game (e.g., place ships)
        void start(); // Method to start the game loop
        bool isGameOver() const; // Method to check if the game is over
};