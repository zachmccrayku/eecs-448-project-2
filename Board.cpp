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
  cout << "Your Board\n";
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
//void Board::viewOBoard(const Board player1, Board player2)
void Board::viewOBoard()
{
  //Ship Player1Opp_grid[9][10];
  //Ship Player2Opp_grid[9][10];
  string space = " ";
  cout << "Opponent's Board\n";
  cout << "  A B C D E F G H I J " << endl;
  for(int x = 0; x < 9; x++)
  {
    cout << x + 1 << " ";

    for(int y = 0; y < 10; y++)
    {
      if(m_grid[x][y].getChar() == '^')
      {
        cout << "_" << space  ;
      }
      if(m_grid[x][y].getChar() =='_')
	{
            cout << "_"<< space ;
	}
	if(m_grid[x][y].getChar() =='X')
	{
		cout << "X"<< space ;
	}
	if(m_grid[x][y].getChar() =='O')
	{
		cout << "O"<< space ;
	}

    }
    cout << endl;

    //if()//is player1
    //  cout << Player1Opp_grid[x][y].getChar() << " " ;

    //if()//is player2
    //  cout <<Player2Opp_grid[x][y].getChar() << " " ;

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

    // cout statement
    cout << "Choose the starting ";
    (isHorizontal ? cout << "leftmost" : cout << "topmost");
    cout << " coordinate where you would like to place your ";
    isHorizontal ? cout << "1 x " << i : cout << i << " x 1";
    cout << " ship.\n";

    convertString();

    row = fireSpotNum;
    col = fireSpotLetter;

    // check if coordinate is valid
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
  convertString();

  m_grid[fireSpotNum][fireSpotLetter].hitShip();

  if(m_grid[fireSpotNum][fireSpotLetter].getChar() != '^')
  {
    canBeFired = true;
    viewOBoard();
    if(m_grid[fireSpotNum][fireSpotLetter].hasBeenHit() == true)
    {
      cout << "Hit\n";
    }
    else
    {
      cout << "Miss\n";
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
