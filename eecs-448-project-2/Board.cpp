#include "Board.h"

Board::Board()
{
  m_numShips = 0;
  m_shipsSunk = 0;
}


Board::~Board(){}


void Board::viewBoard()
{
  cout
    << "Your board:\n"
    << "  A B C D E F G H I J\n";

  for(int x = 0; x < numRows; x++)
  {
    cout << x + 1 << " ";

    for(int y = 0; y < numCols; y++)
      cout << m_grid[x][y].getChar() << " ";

    cout << endl;
  }
}

void Board::viewOBoard()
{
  cout
    << "Your attacks:\n"
    << "  A B C D E F G H I J\n";

  for(int x = 0; x < numRows; x++)
  {
    cout << x + 1 << " ";

    for(int y = 0; y < numCols; y++)
    {
      if(m_grid[x][y].getChar() == '#')
        // UnHit ships are hidden
        cout << " ";
      else if(m_grid[x][y].getChar() == '*')
        // Hit ship '*' showing X
        cout << "X";
      else if(m_grid[x][y].getChar() == 'X')
        // Hit empty spot 'X' showing O
        cout << "O";
      else if(m_grid[x][y].getChar() == '_')
        // Empty spot
        cout << " ";

      cout << " ";

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
    // Show player their current board with ship placements
    viewBoard();

    // choose horizontal or vertical ship placement
    if (i != 1)
    {
      do
      {
        cout << "Place ship horizontally (H) or vertically (V)? ";
        cin >> orientation;
        if (orientation == 'h') orientation = 'H';
        if (orientation == 'v') orientation = 'V';

        if (orientation != 'H' && orientation != 'V')
          cout << "Invalid input. Try again.";

      } while (orientation != 'H' && orientation != 'V');

      isHorizontal = orientation == 'H';
    }

    do {
      cout << "Choose the starting ";
      if(i != 1) isHorizontal ? cout << "leftmost " : cout << "topmost ";
      cout << "coordinate where you would like to place your ";
      isHorizontal ? cout << "1 x " << i : cout << i << " x 1";
      cout << " ship.\n";

      promptForCoordinate();

    } while(!checkValidShipPlacement(i, isHorizontal));

    if (isHorizontal)
      for (int j = 0; j < i; j++)
      {
        m_grid[m_row][m_col+j].placeShip();
        m_grid[m_row][m_col+j].setOrientation(isHorizontal);
      }
    else
      for (int j = 0; j < i; j++)
      {
        m_grid[m_row+j][m_col].placeShip();
        m_grid[m_row+j][m_col].setOrientation(isHorizontal);
      }

    system("clear");
  }

  cout << "Here is your final ship placement:\n";
  viewBoard();
  cout << "\nPress ENTER to Continue ";
  cin.ignore();
  cin.ignore();
  system("clear");
}


void Board::fireAt()
{
  bool invalidHit = true;

  // Change who's turn it is after each hit
  while(invalidHit)
  {
    promptForCoordinate();

    // Check if spot has been previously hit
    if (m_grid[m_row][m_col].hitShip())
    {
      // If spot hit contained a ship
      if (m_grid[m_row][m_col].hasBeenHit() && m_grid[m_row][m_col].isShip())
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
          cout << "You have sunk all of your enemy's ships!\n";
      }

      else // if spot hit did not contain a ship
      {
        invalidHit = false;
        cout << "\nYou missed.\n";
      }
    }

    else
      cout << "This spot has already bit hit. Try again.\n";

  }

  cout << "\nPress ENTER to Continue ";
  cin.ignore();
  cin.ignore();
}

void Board::promptForCoordinate()
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

      // Row number
      if (m_row >= 49 && m_row <=57)
      {
        m_row = m_row - 49;

        // Column letter, uppercase
        if (m_col >= 65 && m_col <= 74)
        {
          m_col = m_col - 65;
          validInput = true;
        }

        // Column letter, lowercase
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


bool Board::checkValidShipPlacement(int shipSize, bool horizontal)
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
      if (
        (
          m_col > 0
          && m_grid[m_row][m_col-1].isShip()
        )
        || ( // Check if no ships to left or right
         m_col+shipSize < numCols
         && m_grid[m_row][m_col+shipSize].isShip()
        )
      )
      {
        validInput = false;
        invalidCoordMessage = "Cannot place ships adjacent to one another.";
      }

      for (int j = 0; j < shipSize; j++)
      {
        // If another ship takes up this space
        if (m_grid[m_row][m_col+j].isShip())
        {
          validInput = false;
          invalidCoordMessage = "Ships overlap.";
          break;
        }

        // Check no ships above
        if (m_row > 0)
        {
          if (m_grid[m_row-1][m_col+j].isShip())
          {
            validInput = false;
            invalidCoordMessage = "Cannot place ships adjacent to one another.";
            break;
          }
        }

        // Check no ships below
        if (m_row < numRows-1)
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
      if (
        (
          m_row > 0
          && m_grid[m_row-1][m_col].isShip()
        )
        || ( // check if no ships on top or below
          m_row+shipSize < m_row
          && m_grid[m_row+shipSize][m_col].isShip()
        )
      )
      {
        validInput = false;
        invalidCoordMessage = "Cannot place ships adjacent to one another.";
      }

      for (int j = 0; j < shipSize; j++)
      {
        // If another ship takes up this space
        if (m_grid[m_row+j][m_col].isShip())
        {
          validInput = false;
          invalidCoordMessage = "Ships overlap.";
          break;
        }

        // Check no ships left
        if (m_col > 0)
        {
          if (m_grid[m_row+j][m_col-1].isShip())
          {
            validInput = false;
            invalidCoordMessage = "Cannot place ships adjacent to one another.";
            break;
          }
        }

        // Check no ships right
        if (m_col < numCols-1)
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

  return validInput;

}

bool Board::isOnGrid(int row, int col)
{
  return (
    row >= 0
    && row < numRows
    && col >= 0
    && col < numCols
  );
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
        return false;

      temp--;

      if (!isOnGrid(row, temp))
        break;
    }

    temp = col;
    while (m_grid[row][temp].isShip())
    {
      if (m_grid[row][temp].hasBeenHit() == false)
        return false;

      temp++;

      if (!isOnGrid(row, temp))
        break;
    }

  }

  else
  {
    temp = row;
    while (m_grid[temp][col].isShip())
    {
      if (m_grid[temp][col].hasBeenHit() == false)
        return false;

      temp--;

      if (!isOnGrid(temp, col))
        break;
    }

    temp = row;
    while (m_grid[temp][col].isShip())
    {
      if (m_grid[temp][col].hasBeenHit() == false)
        return false;

      temp++;

      if (!isOnGrid(temp, col))
        break;
    }
  }

  return true;
}


bool Board::hasLost()
{
  return m_shipsSunk == m_numShips;
}
