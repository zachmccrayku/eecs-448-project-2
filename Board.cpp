#include "Board.h"
#include "Ship.h"
#include <iostream>

using namespace std;

Board::~Board()
{

}

Board::Board()
{
    for(int x = 0; x < 9; x++)
    {
        for(int y = 0; y < 10; y++)
        {   
            grid[x][y]='|';
        
        }
    }
}

void Board::printBoard()
{
    
      cout << "   A B C D E F G H I J " << endl;

    for(int x = 0; x < 9; x++)
  {
      cout << x + 1 << " ";

    for(int y = 0; y < 10; y++)
    {
      cout << grid[x][y] << "_";
    }
    cout << endl;
  }
}   
