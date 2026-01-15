/*======================================
created by Alex Tkachenkov & Niv Badichi
  ======================================*/






#include <iostream>
#include "Game.hpp"
#include "HumanPlayer.hpp"
#include "AiPlayer.hpp"
using namespace std;

int main() {
    cout << "=== Welcome to Battleship ===" << endl;
    cout << "Choose Game Mode:" << endl;
    cout << "1. Human vs Human" << endl;
    cout << "2. Human vs AI" << endl;

    int mode;
    cin >> mode;

    if (mode != 1 && mode != 2) {
        cout << "Invalid selection. Exiting game." << endl;
        return 1;
    }

    if (mode == 1) {
        string name1, name2;
        cout << "Enter name for Player 1: ";
        cin >> name1;
        cout << "Enter name for Player 2: ";
        cin >> name2;

        HumanPlayer* p1 = new HumanPlayer(name1.c_str());
        HumanPlayer* p2 = new HumanPlayer(name2.c_str());

        Game game(p1, p2);
        game.setup();
        game.start();

        // //debug
        // std::cout <<"IN MAIN.CPP after game.start()"<<endl;
        // std::cout <<"Human V HumanGame ended, Deleting players"<<endl;
        // //
        // delete p1;
        // delete p2;
        // //debug
        // std::cout << "Players deleted." << std::endl;
        
} else if (mode == 2) {
        string name;
        cout << "Enter your name: ";
        cin >> name;

        HumanPlayer* p1 = new HumanPlayer(name.c_str());
        AiPlayer* p2 = new AiPlayer("Computer");

        Game game(p1, p2);
        game.setup();
        game.start();
        
        // //debug
        // std::cout <<"IN MAIN.CPP after game.start()"<<endl;
        // std::cout <<"Human V AIGame ended, Deleting players"<<endl;
        // //
        // delete p1;
        // delete p2;
        // //debug
        // std::cout << "Players deleted." << std::endl;
        // //
    }

    cout << "Thank you for playing Battleship!" << endl;
    return 0;
}