#include "Board.h"

Board::Board()
{
  m_numShips = 0;
}

Board::~Board(){}

void Board::viewBoard()
{
  cout << "Your board:\n";
  cout << "  A B C D E F G H I J " << endl;

  for(int x = 0; x < 9; x++)
  {
    cout << x + 1 << " ";

    for(int y = 0; y < 10; y++)
    {
      cout << m_grid[x][y].getChar() << " ";
    }
    cout << endl;
  }

}

void Board::viewOBoard()
{
  cout << "Opponent's board:\n";
  cout << "  A B C D E F G H I J " << endl;
  for(int x = 0; x < 9; x++)
  {
    cout << x + 1 << " ";

    for(int y = 0; y < 10; y++)
    {
      if      (m_grid[x][y].getChar() == '^'){cout << "_ ";}
      else if (m_grid[x][y].getChar() == '*'){cout << "X ";}
      else    {cout << m_grid[x][y].getChar() << " ";}
    }

    cout << endl;
  }

}


void Board::shipPlacement(int numShips)
{
  m_numShips = numShips;

  bool isHorizontal = true;
  char orientation;
  string coordinate;
  int row;
  int col;

  for (int i = 1; i <= m_numShips; i++)
  {
    viewBoard(); // show player their current board with ship placements

    // choose horizontal or vertical ship placement
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


    bool invalidCoord;
    do {
      invalidCoord = false;

      // cout statement asking for coordinate
      cout << "Choose the starting ";
      if (i != 1) isHorizontal ? cout << "leftmost " : cout << "topmost ";
      cout << "coordinate where you would like to place your ";
      isHorizontal ? cout << "1 x " << i : cout << i << " x 1";
      cout << " ship.\n";

      // obtain row and column from user
      convertCoord();

      row = m_row;
      col = m_col;

      if (isHorizontal)
      {
        if (col + i > numCols)
        {
          invalidCoord = true;
        }

        else
        {
          for (int j = 0; j < i; j++)
          {
            if (m_grid[row][col+j].isShip() == 1)
            {
              invalidCoord = true;
            }
          }

        }
      }

      else if (!isHorizontal)
      {
        if ((row + i > numRows))
        {
          invalidCoord = true;
        }

        else
        {
          for (int j = 0; j < i; j++)
          {
            if (m_grid[row+j][col].isShip() == 1)
            {
              invalidCoord = true;
            }
          }
        }
      }

      if (invalidCoord)
      {
        cout << "ERROR: Ships overlap, are adjacent, or go off grid. Choose another coordinate.\n\n";
      }

    } while(invalidCoord);

    row = m_row;
    col = m_col;

    if (isHorizontal)
    {
      for (int j = 0; j < i; j++)
      {
        m_grid[row][col+j].placeShip();
        m_grid[row][col+j].setOrientation(isHorizontal);
      }
    }

    else
    {
      for (int j = 0; j < i; j++)
      {
        m_grid[row+j][col].placeShip();
        m_grid[row+j][col].setOrientation(isHorizontal);
      }
    }

    system("clear");

    // loop to next iteration

  }

}

void Board::fireAt()
{
  canBeFired = false;
  convertCoord();

  m_grid[m_row][m_col].hitShip();

  if(m_grid[m_row][m_col].getChar() != '^')
  {
    canBeFired = true;
    viewOBoard();
    if(m_grid[m_row][m_col].hasBeenHit() == true)
    {
      cout << "Hit\n";
    }
    else
    {
      cout << "Miss\n";
    }

  }

  cout << "Press Enter to Continue ";
  cin.ignore();
  cin.ignore();
}

void Board::convertCoord()
{
  canBeFired = false;
  do
  {
    cout << "Choose a Coordinate: ";
    cin >> fireAtSpot;
    if(fireAtSpot.length() == 2)
    {
      m_col = int(fireAtSpot.at(0));
      m_row = int(fireAtSpot.at(1));
      if(m_row >= 49 || m_row <=57)
      {
        m_row = m_row-49;
        if(m_col >= 65 || m_col <= 74)
        {
          m_col= m_col - 65;
          canBeFired = true;
        }
        else if(m_col >= 97 || m_col <= 106)
        {
          m_col= m_col - 97;
          canBeFired = true;
        }
      }

      else
      {
        cout << "Error! Try Again!";
      }
    }

  } while(canBeFired == false);
}

bool Board::isSunk(int row, int col)
{
  bool Sunk = false;
  if(m_grid[row][col].isHorizontal() == true)
  {
    for(int i = col; i < numCols; i++)
    {
      if(m_grid[row][i].getChar() == '^')
      {
        return (Sunk);
      }
      if(m_grid[row][i].getChar() == '_')
      {
        if(m_grid[row][i-1].getChar() == '^')
        {
          return(Sunk);
        }
        else if(i-1 != 0)
        {
          isSunk(row, i-1);
        }
        else if(m_grid[row][i-1].getChar() == 'X')
        {
          Sunk = true;
          return(Sunk);
          counter++;
        }
      }
      break;
    }
  }

  else
  {
    for(int i = row; i < numRows; i++)
    {
      if(m_grid[i][col].getChar() == '^')
      {
        return (Sunk);
      }
      if(m_grid[i][col].getChar() == '_')
      {
        if(m_grid[i-1][col].getChar() == '^')
        {
          return(Sunk);
        }
        else if(i-1 != 0)
        {
          return(isSunk(i-1, col));
        }
        else if(m_grid[i-1][col].getChar() == 'X')
        {
          counter++;
          Sunk=true;
          return(Sunk);
        }
      }
      break;
    }
  }
  return(Sunk);
}

bool Board::checkWin()
{
  return(counter == m_numShips);
}
