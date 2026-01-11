#include <iostream>
#include "Grid.hpp"
#include "HumanPlayer.hpp"
using namespace std;

void HumanPlayer::getInput(int &row, int &col, bool &orientation)
{
    char orientChar;
    cout << "Enter row (1-10): ";
    cin >> row;
    while (row < 1 || row > 10)
    {
        cout << "Invalid row. Try again." << endl;
        cin >> row;
    }
    row--; // Adjust for 0-based index
    cout << "Enter column (1-10): ";
    cin >> col;
    while (col < 1 || col > 10)
    {
        cout << "Invalid column. Try again." << endl;
        cin >> col;
    }
    col--; // Adjust for 0-based index
    cout << "Enter orientation (H for horizontal, V for vertical): ";
    cin >> orientChar;
    while (orientChar != 'H' && orientChar != 'h' && orientChar != 'V' && orientChar != 'v')
    {
        cout << "Invalid orientation. Try again." << endl;
        cin >> orientChar;
    }
    orientation = (orientChar == 'H' || orientChar == 'h');
}

void HumanPlayer::placeAllShips()
{
    cout << playerName << ", place your ships on the grid." << endl;
    ocean.printGrid(true);

    cout << "choose where to place Carrier (length 5)" << endl;
    int row, col;
    bool horizontal;
    getInput(row, col, horizontal);
    bool horizontal = (horizontal == 'H' || horizontal == 'h');
    if (!ocean.validatePlacement(row, col, 5, horizontal))
    {
        cout << "Invalid placement. Try again." << endl;
        getInput(row, col, horizontal);
    }
    this->ocean.placeShip(row, col, 5, horizontal, 'C');
    ocean.printGrid(true);

    cout << "choose where to place Battleship (length 4)" << endl;
    getInput(row, col, horizontal);
    if (!ocean.validatePlacement(row, col, 4, horizontal))
    {
        cout << "Invalid placement. Try again." << endl;
        getInput(row, col, horizontal);
    }
    this->ocean.placeShip(row, col, 4, horizontal, 'B');
    ocean.printGrid(true);

    cout << "choose where to place cruiser (length 3)" << endl;
    getInput(row, col, horizontal);
    if (!ocean.validatePlacement(row, col, 3, horizontal))
    {
        cout << "Invalid placement. Try again." << endl;
        getInput(row, col, horizontal);
    }
    this->ocean.placeShip(row, col, 3, horizontal, 'R');
    ocean.printGrid(true);

    cout << "choose where to place Submarine (length 3)" << endl;
    getInput(row, col, horizontal);
    if (!ocean.validatePlacement(row, col, 3, horizontal))
    {
        cout << "Invalid placement. Try again." << endl;
        getInput(row, col, horizontal);
    }
    this->ocean.placeShip(row, col, 3, horizontal, 'R');
    ocean.printGrid(true);
    
    cout << "choose where to place Destroyer (length 2)" << endl;
    getInput(row, col, horizontal);
    if (!ocean.validatePlacement(row, col, 2, horizontal))
    {
        cout << "Invalid placement. Try again." << endl;
        getInput(row, col, horizontal);
    }
    this->ocean.placeShip(row, col, 2, horizontal, 'D');
    
    // Repeat for other ships: Battleship (4), Cruiser (3), Submarine (3), Destroyer (2)

}
