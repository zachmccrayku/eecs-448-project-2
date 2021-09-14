#ifndef BOARD_H
#define BOARD_H

#include "Ship.h"
using namespace std;

class Board
{
private:
  int numRows = 9;
  int numCols = 10;
  Ship m_grid[9][10]; // 2D array, of type Ship
  int m_numShips;

public:
  Board(); // initialize 9x10 board
  ~Board();

    /*
     *Allows players to view their board as well as the opponents board with their hits and misses
     *@param None
     */
    void viewBoard();

    /*
     *Ship is placed on the board
     *@param
     */
    void shipPlacement();
};

#endif
