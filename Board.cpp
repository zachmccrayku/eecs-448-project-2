/**
File Name: Board.cpp
Authors: Regan Janssen, Andrew Loaiza, Chen Lu, Jui Nagarkar, Natasha Shirley
Description: Defines the main functionality for the game 
Date: Sept. 19, 2021
*/

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
{
  cout << "Your attacks:\n";
  cout << "  A B C D E F G H I J " << endl;
  for(int x = 0; x < numRows; x++)
  {
    cout << x + 1 << " ";

    for(int y = 0; y < numCols; y++)
    {
      if      (m_grid[x][y].getChar() == '^'){cout << "_ ";} // unhit ships are hidden
      else if (m_grid[x][y].getChar() == '*'){cout << "X ";} // hit ship '*' showing X
      else if (m_grid[x][y].getChar() == 'X'){cout << "O ";} // hit empty spot 'X' showing'O'
      else if (m_grid[x][y].getChar() == '_'){cout << "_ ";} // empty spot
      ///////// we need to add logic and then character for sunken ship
      //////// we need to mark adjacent coordinates as "hit" since there cannot be a ship there
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
  bool invalidHit = true;

  while(invalidHit) // After each shot, it is the other players turn.
  {
    convertCoord(); // ask user for coordinate to hit

    if (m_grid[m_row][m_col].hitShip()) // checks if spot has been previously hit
    {
      if (m_grid[m_row][m_col].hasBeenHit() && m_grid[m_row][m_col].isShip()) // if spot hit contained a ship
      {
        m_grid[m_row][m_col].hitShip();
        invalidHit = false;
        cout << "You hit an enemy ship!\n";

        if (isSunk(m_row, m_col))
        {
          cout << "You have sunk an enemy ship!\n";
          m_shipsSunk++;
        }

        if (hasLost())
        {
          cout << "You have sunk all of your enemy's ships!\n";
        }
      }

      else // if spot hit did not contain a ship
      {
        invalidHit = false;
        cout << "\nYou missed.\n";
      }
    }

    else
    {
      cout << "This spot has already bit hit. Try again.\n";
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
      if ( ((m_col > 0) && (m_grid[m_row][m_col-1].isShip())) || // check if no ships to left or right
         (((m_col+shipSize) < numCols) && (m_grid[m_row][m_col+shipSize].isShip())) )
      {
        validInput = false;
        invalidCoordMessage = "Cannot place ships adjacent to one another.";
      }

      for (int j = 0; j < shipSize; j++)
      {
        if (m_grid[m_row][m_col+j].isShip()) // if another ship takes up this space
        {
          validInput = false;
          invalidCoordMessage = "Ships overlap.";
          break;
        }

        if (m_row > 0) // check no ships above
        {
          if (m_grid[m_row-1][m_col+j].isShip())
          {
            validInput = false;
            invalidCoordMessage = "Cannot place ships adjacent to one another.";
            break;
          }
        }

        if (m_row < numRows-1) // check no ships below
        {
          if (m_grid[m_row+1][m_col+j].isShip())
          {
            validInput = false;
            invalidCoordMessage = "Cannot place ships adjacent to one another.";
            break;
          }
        }

      }
    }

  }

  else
  {
    if ((m_row + shipSize > numRows))
    {
      validInput = false;
      invalidCoordMessage = "Ship goes off grid.";
    }

    else
    {
      if ( ((m_row > 0) && (m_grid[m_row-1][m_col].isShip())) || // check if no ships on top or below
         (((m_row+shipSize) < m_row) && (m_grid[m_row+shipSize][m_col].isShip())) )
      {
        validInput = false;
        invalidCoordMessage = "Cannot place ships adjacent to one another.";
      }

      for (int j = 0; j < shipSize; j++)
      {
        if (m_grid[m_row+j][m_col].isShip()) // if another ship takes up this space
        {
          validInput = false;
          invalidCoordMessage = "Ships overlap.";
          break;
        }

        if (m_col > 0) // check no ships left
        {
          if (m_grid[m_row+j][m_col-1].isShip())
          {
            validInput = false;
            invalidCoordMessage = "Cannot place ships adjacent to one another.";
            break;
          }
        }

        if (m_col < numCols-1) // check no ships right
        {
          if (m_grid[m_row+j][m_col+1].isShip())
          {
            validInput = false;
            invalidCoordMessage = "Cannot place ships adjacent to one another.";
            break;
          }
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
    temp = row;
    while (m_grid[temp][col].isShip())
    {
      if (m_grid[temp][col].hasBeenHit() == false)
      {
        return(false);
      }

      temp--;

      if (!isOnGrid(temp, col)) break;
    }

    temp = row;
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
