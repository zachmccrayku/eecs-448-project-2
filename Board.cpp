#include "Board.h"

Board::Board()
{
  m_numShips = 0;
}

Board::~Board(){}

void Board::getNumShips(int numShips)
{
  m_numShips = numShips;
}
