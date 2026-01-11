#include <iostream>
#include "Grid.hpp"
#include "HumanPlayer.hpp"
using namespace std;

void HumanPlayer::getInput(int &row, int &col, char &orientation)
{
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
    cin >> orientation;
    while (orientation != 'H' && orientation != 'h' && orientation != 'V' && orientation != 'v')
    {
        cout << "Invalid orientation. Try again." << endl;
        cin >> orientation;
    }
}

void HumanPlayer::placeAllShips()
{
    cout << playerName << ", place your ships on the grid." << endl;
    ocean.printGrid(true);
    cout << "choose where to place Carrier (length 5)" << endl;
    int row, col;
    char orientation;
    getInput(row, col, orientation);
    row--; // Adjust for 0-based index
    col--; // Adjust for 0-based index
    bool horizontal = (orientation == 'H' || orientation == 'h');
    if (!ocean.validatePlacement(row, col, 5, horizontal))
    {
        cout << "Invalid placement. Try again." << endl;
        getInput(row, col, orientation);
        horizontal = (orientation == 'H' || orientation == 'h');
    }
    this->ocean.placeShip(row, col, 5, horizontal, 'C');
    ocean.printGrid(true);
    cout << "choose where to place Battleship (length 4)" << endl;
    int row, col;
    char orientation;
    getInput(row, col, orientation);
    bool horizontal = (orientation == 'H' || orientation == 'h');
    if (!ocean.validatePlacement(row, col, 4, horizontal))
    {
        cout << "Invalid placement. Try again." << endl;
        getInput(row, col, orientation);
        horizontal = (orientation == 'H' || orientation == 'h');
    }
    this->ocean.placeShip(row, col, 4, horizontal, 'B');
    
    // Repeat for other ships: Battleship (4), Cruiser (3), Submarine (3), Destroyer (2)

}
