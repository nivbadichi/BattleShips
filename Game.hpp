#pragma once
#include "player.hpp"
class Game {
    private:
    Player* player1;    //probably human
    Player* player2;    //probably AI
    
    public:
    Game(Player* p1, Player* p2);   //Assigns two player objects (e.g., HumanPlayer vs. AiPlayer).
    void setup();                   //Calls player1->placeAllShips();, then player2->placeAllShips();.
    void start();                   //Loop until one side is fully sunk:
    //player1->makeMove(player2);     
    //Check player2->allShipsSunk().
    //player2->makeMove(player1);     
    //Check player1->allShipsSunk().
    //Announce the winner when a fleet is sunk.
    bool isGameOver() const;        //Returns true if player1->allShipsSunk() or player2->allShipsSunk().
};