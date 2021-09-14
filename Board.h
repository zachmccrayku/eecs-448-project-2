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

public:
  Board(); // initialize 9x10 board
  ~Board();
  void viewBoard();
  void shipPlacement();
};

#endif
