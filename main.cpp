// THIS IS AN EXAMPLE!!! YOU CAN CHANGE IT

#include <iostream>
#include <cstdlib> // For std::rand(), std::srand()
#include <ctime>   // For std::time()
#include "Game.h"
#include "HumanPlayer.h"
#include "AiPlayer.h"

int main()
{
    // Seed the random number generator for AI placement and moves
    // You need it to stay HERE when you use random in the AiPlayer class
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Create two players: one human, one AI
    Player *p1 = new HumanPlayer("Human");
    Player *p2 = new AiPlayer("Computer");
    
    p1->placeAllShips();
    p2->placeAllShips();
    p2->ocean.printGrid(true);

    return 0;
}
