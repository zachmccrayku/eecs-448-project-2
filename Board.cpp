#include "Board.h"

Board::Board()
{
  m_numShips = 0;
}

Board::~Board()
{

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


void Board::shipPlacement()
{
  // set ships onto grid
  // called from UserInteraction

  bool isHorizontal = true;
  char orientation;
  string coordinate;
  int row;
  int col;

  for (int i = 1; i <= m_numShips; i++)
  {
    viewBoard(); // show player their current board with ship placements

    // let user choose horizontal or vertical ship placement
    if (i != 1)
    {
      do
      {
        cout << "Do you want to place your ship horizontal (H) or vertical (V)?: ";
        cin >> orientation;

        if (orientation != 'H' && orientation != 'V') cout << "Inavlid input. Try again.";

      } while (orientation != 'H' && orientation != 'V');

      if (orientation == 'V')
      {
        isHorizontal = false;
        // by default initialized to true in Ship class
      }
    }

    // let user choose coordinate
    cout << "Choose the starting ";
    (isHorizontal ? cout << "leftmost" : cout << "topmost");
    cout << " coordinate where you would like to place your ship.\n";

    // cout << "Input number and letter [A-J][1-10]: ";
    // cin >> coordinate;
    //
    // for (int i = 0; i < coordinate.length(); i++)
    // {
    //
    // }

    do {
      cout << "Input (array) row number (testing): ";
      cin >> row;
    } while(row < 0 || row >= numRows);

    do {
      cout << "Input (array) column number (testing): ";
      cin >> col;
    } while(col < 0 || col >= numCols);

    // check if coordinate is valid
    if (isHorizontal)
    {
      for (int j = col; j < i; j++)
      {
        m_grid[row][j].placeShip();
        m_grid[row][j].makeHorizontal(isHorizontal);
      }
    }

    else
    {
      for (int j = row; j < i; j++)
      {
        m_grid[j][col].placeShip();
        m_grid[j][col].makeHorizontal(isHorizontal);
      }
    }
    
    // loop to next iteration

  }
}
