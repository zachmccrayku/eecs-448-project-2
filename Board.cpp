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

void Board::shipPlacement(int numShips)
{
  // set ships onto grid
  // could go in UserInteraction
}

void Board::viewBoard()
{
  // view player's own board
  // view oppoenent's board

  cout << "  A B C D E F G H I J " << endl;

  for(int x = 0; x < 9; x++)
  {
      cout << x + 1 << " ";

    for(int y = 0; y < 10; y++)
    {
      cout << m_grid[x][y].gridChar << " ";
    }
    cout << endl;
  }

}
