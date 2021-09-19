#include "Board.h"

Board::Board()
{
  m_numShips = 0;
  m_shipsSunk = 0;
}


Board::~Board(){}


void Board::viewBoard()
{
  cout << "Your board:\n";
  cout << "  A B C D E F G H I J " << endl;

  for(int x = 0; x < numRows; x++)
  {
    cout << x + 1 << " ";

    for(int y = 0; y < numCols; y++)
    {
      cout << m_grid[x][y].getChar() << " ";
    }

    cout << endl;
  }
}


void Board::viewOBoard()
{ string space= " ";
  cout << "Your attacks:\n";
  cout << "  A B C D E F G H I J " << endl;
  for(int x = 0; x < numRows; x++)
  {
    cout << x + 1 << " ";

    for(int y = 0; y < numCols; y++)
    {
      if (m_grid[x][y].getChar() == '^'){cout << "_" + space ;}
      else if (m_grid[x][y].getChar() == '*'){cout << "X"+space;}
      else if (m_grid[x][y].getChar() == 'O') {cout << "O"+space;}
      else if (m_grid[x][y].getChar() =='_') {cout << "_"+ space;}
    }

    cout << endl;
  }
}


void Board::shipPlacement(int numShips)
{
  m_numShips = numShips;
  bool isHorizontal = true;
  char orientation;
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
        if (orientation == 'h') orientation = 'H';
        if (orientation == 'v') orientation = 'V';

        if (orientation != 'H' && orientation != 'V')
        {
          cout << "Inavlid input. Try again.";
        }

      } while (orientation != 'H' && orientation != 'V');

      if (orientation == 'V')
      {
        isHorizontal = false;
      }
    }

    do {
      validInput = false;

      // cout statement asking for coordinate
      cout << "Choose the starting ";
      if (i != 1) isHorizontal ? cout << "leftmost " : cout << "topmost ";
      cout << "coordinate where you would like to place your ";
      isHorizontal ? cout << "1 x " << i : cout << i << " x 1";
      cout << " ship.\n";

      // obtain row and column from user
      convertCoord();

      // check if shiip can be placed here
      checkValidShipPlacement(i, isHorizontal);

    } while(validInput == false);

    if (isHorizontal)
    {
      for (int j = 0; j < i; j++)
      {
        m_grid[m_row][m_col+j].placeShip();
        m_grid[m_row][m_col+j].setOrientation(isHorizontal);
      }
    }

    else
    {
      for (int j = 0; j < i; j++)
      {
        m_grid[m_row+j][m_col].placeShip();
        m_grid[m_row+j][m_col].setOrientation(isHorizontal);
      }
    }

    system("clear");
  } // loop to next iteration

  cout << "Here is your final ship placement:\n";
  viewBoard();
  cout << "\nPress Enter to Continue ";
  cin.ignore();
  cin.ignore();
  system("clear");
}


void Board::fireAt()
{
  bool validHit = true;

  convertCoord(); // this already checks for hit within bounds
  while(validHit) // After each shot, it is the other players turn.
  {
    if (m_grid[m_row][m_col].hitShip()) // checks if spot has been previously hit
    {

      if (m_grid[m_row][m_col].hasBeenHit() && m_grid[m_row][m_col].isShip()) // if spot hit contained a ship
      {
        m_grid[m_row][m_col].hitShip();
        validHit = false;
        cout << "You hit an enemy ship!\n";

        if (isSunk(m_row, m_col))
        {
          cout << "You have sunk an enemy ship!\n";
          validHit = false;
          m_shipsSunk++;
        }

        if (hasLost())
        {
          validHit = false;
          cout << "You have sunk all of your enemy's ships!\n";
        }
      }

      else // if spot hit did not contain a ship
      {
        validHit = false;

        cout << "\nYou missed.\n";
      }
    }

    else
    {
      cout << "This spot has already bit hit. Try again.\n";
      convertCoord();
    }
  }

  cout << "\nPress Enter to Continue ";
  cin.ignore();
  cin.ignore();


}

void Board::convertCoord()
{
  validInput = false;

  do
  {
    cout << "Choose a Coordinate: ";
    cin >> userInput;

    if(userInput.length() == 2)
    {
      m_col = int(userInput.at(0));
      m_row = int(userInput.at(1));

      // row number
      if (m_row >= 49 && m_row <=57)
      {
        m_row = m_row - 49;

        // column letter, uppercase
        if (m_col >= 65 && m_col <= 74)
        {
          m_col = m_col - 65;
          validInput = true;
        }

        // column letter, lowercase
        else if (m_col >= 97 && m_col <= 106)
        {
          m_col = m_col - 97;
          validInput = true;
        }
      }
    }

    if (!validInput)
    {
      cout << "ERROR: Input a valid coordinate, [A-J][1-9], for example, A1.\n";
    }

  } while(!validInput);
}


void Board::checkValidShipPlacement(int shipSize, bool horizontal)
{
  validInput = true;

  if (horizontal)
  {
    if (m_col + shipSize > numCols)
    {
      validInput = false;
      invalidCoordMessage = "Ship goes off grid.";
    }

    else
    {
      for (int j = 0; j < shipSize; j++)
      {
        if (m_grid[m_row][m_col+j].isShip())
        {
          validInput = false;
          invalidCoordMessage = "Ships overlap.";
          break;
        }
      }
    }
  }

  else if (horizontal)
  {
    if ((m_row + shipSize > numRows))
    {
      validInput = false;
      invalidCoordMessage = "Ship goes off grid.";
    }

    else
    {
      for (int j = 0; j < shipSize; j++)
      {
        if (m_grid[m_row+j][m_col].isShip())
        {
          validInput = false;
          invalidCoordMessage = "Ships overlap.";
          break;
        }
      }
    }
  }

  if (validInput == false)
  {
    cout << "ERROR: " << invalidCoordMessage << "\n\n";
  }

}

bool Board::isOnGrid(int row, int col)
{
  if (row >= 0 && row < numRows)
  {
    if (col >= 0 && col < numCols)
    {
      return(true);
    }
  }

  return(false);
}

bool Board::isSunk(int row, int col)
{
  int temp;

  if(m_grid[row][col].isHorizontal() == true)
  {
    temp = col;
    while (m_grid[row][temp].isShip())
    {
      if (m_grid[row][temp].hasBeenHit() == false)
      {
        return(false);
      }

      temp--;

      if (!isOnGrid(row, temp)) break;
    }

    temp = col;
    while (m_grid[row][temp].isShip())
    {
      if (m_grid[row][temp].hasBeenHit() == false)
      {
        return(false);
      }

      temp++;

      if (!isOnGrid(row, temp)) break;
    }

  }

  else
  {
    temp = col;
    while (m_grid[temp][col].isShip())
    {
      if (m_grid[temp][col].hasBeenHit() == false)
      {
        return(false);
      }

      temp--;

      if (!isOnGrid(temp, col)) break;
    }

    temp = col;
    while (m_grid[temp][col].isShip())
    {
      if (m_grid[temp][col].hasBeenHit() == false)
      {
        return(false);
      }

      temp++;

      if (!isOnGrid(temp, col)) break;
    }
  }

  return(true);
}


bool Board::hasLost()
{
  return(m_shipsSunk == m_numShips);
}
