#ifndef BOARD_H
#define BOARD_H

#include "Ship.h"
using namespace std;

class Board
{
private:
  Grid m_grid; // 2D array, of type Ship
  int m_numShips;

public:
  Board(); // initialize 9x10 board
  ~Board();
  void numShips(); // store number of ships in m_numShips
  void shipPlacement(int numShips); // place ships onto board
  void viewBoard(); // can show attacks sent to enemy board, or players own board
};

#endif
