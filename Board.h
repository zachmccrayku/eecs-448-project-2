#ifndef BOARD_H
#define BOARD_H

#include "Ship.h"
using namespace std;

class Board
{
private:
  int numRows = 9; // Sets the number of rows for the board 
  int numCols = 10; // Sets the number of columns for the board 
  Ship m_grid[9][10]; // 2D array, of type Ship

public:
  /*
  *Initializes a 9x10 board
  *@param None
  */
  Board();

  ~Board(); // avoid memory leaks!
  
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
