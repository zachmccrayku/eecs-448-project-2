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
  cout << "Your Board"\n;
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
void Board::viewOBoard()
{
    cout << "Opponent's Board"\n;
    cout << "  A B C D E F G H I J " << endl;
    for(int x = 0; x < 9; x++)
    {
        cout << x + 1 << " ";
    
        for(int y = 0; y < 10; y++)
        {

            if(m_grid[x][y].getChar() == '^')
            {
                cout << "_";
            }
            else
            {
                cout << m_grid[x][y].getChar();
            }
            cout << m_grid[x][y].getChar() << " ";
        }
        cout << endl;
    }

}


void Board::shipPlacement(int numShips)
{
  // set ships onto grid
  // called from UserInteraction

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

    // choose coordinates for ship
    // call method for obtaining coordinates [A][1]
    // method should return two ints, corressponding to indices for 2D-array

    cout << "Choose the starting ";
    (isHorizontal ? cout << "leftmost" : cout << "topmost");
    cout << " coordinate where you would like to place your ";
    isHorizontal ? cout << "1 x " << i : cout << i << " x 1";
    cout << " ship.\n";

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
      for (int j = 0; j < i; j++)
      {
        m_grid[row][col+j].placeShip();
        m_grid[row][col+j].makeHorizontal(isHorizontal);
      }
    }

    else
    {
      for (int j = 0; j < i; j++)
      {
        m_grid[row+j][col].placeShip();
        m_grid[row+j][col].makeHorizontal(isHorizontal);
      }
    }

    system("clear");

    // loop to next iteration

  }

}

void Board::fireAt()
{
  canBeFired = false;
  convertString();

  m_grid[fireSpotNum][fireSpotLetter].hitShip();

  if(m_grid[fireSpotNum][fireSpotLetter].getChar() != '^')
  {
    canBeFired = true;
    viewOBoard();
    if(m_grid[fireSpotNum][fireSpotLetter].m_hasBeenHit == true)
    {
      cout << "Hit";
    }
    else
    {
      cout << "Miss";
    }
    
  }
  cout << "Press Any Key to Continue";
  cin >> fireAtSpot;
}

void Board::convertString()
{
  canBeFired = false;
  do
  {
    cout << "Choose a Coordinate: ";
    cin >> fireAtSpot;
    if(fireAtSpot.length() == 2)
    {
      fireSpotLetter = int(fireAtSpot.at(0));
      fireSpotNum = int(fireAtSpot.at(1));
      if(fireSpotNum >= 49 || fireSpotNum <=57)
      {
        fireSpotNum = fireSpotNum-49;
        if(fireSpotLetter >= 65 || fireSpotLetter <= 74)
        {
          fireSpotLetter= fireSpotLetter - 65;
          canBeFired = true;
        }
        else if(fireSpotLetter >= 97 || fireSpotLetter <= 106)
        {
          fireSpotLetter= fireSpotLetter - 97;
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
  if(m_grid[row][col].m_isHorizontal == true)
  {
    for(int i = col; i < numCols; i++)
    {
      if(m_grid[row][i].getChar() == '^')
      {
        return (false);
      }
      if(m_grid[row][i].getChar() == '_')
      {
        if(m_grid[row][i-1].getChar() == '^')
        {
          return(false);
        }
        else if(i-1 != 0)
        {
          isSunk(row, i-1);
        }
        else if(m_grid[row][i-1].getChar() == 'X')
        {
          return(true);
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
        return (false);
      }
      if(m_grid[i][col].getChar() == '_')
      {
        if(m_grid[i-1][col].getChar() == '^')
        {
          return(false);
        }
        else if(i-1 != 0)
        {
          return(isSunk(i-1, col));
        }
        else if(m_grid[i-1][col].getChar() == 'X')
        {
          counter++;
          return(true);
        }
      }
      break;
    }
  }
}
