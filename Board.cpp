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


void Board::shipPlacement(int numShips)
{
  // set ships onto grid
  // called from UserInteraction
  system("clear");

  m_numShips = numShips;

  bool isHorizontal = true;
  char orientation;
  string coordinate;
  int row;
  int col;

  for (int i = 1; i <= m_numShips; i++)
  {
    system("clear");
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
    cout << " coordinate where you would like to place your ship.\n";

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

    // loop to next iteration

  }

  system("clear");
  cout << "Here is your final ship placement! Good luck!\n";
  viewBoard();
}

void GamePlay::fireAt()
{
    canBeFired == false;
   do
   {
    m_grid[i][j].hitShip();
    if(m_grid[i][j].getChar() != '^')
    {
      canBeFired == true;
    }
   }
  while(canBeFired == false);
 }

void Board::convertString()
{
  canBeFired == false;
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
          }
         else if(fireSpotLetter >= 97 || fireSpotLetter <= 106)
         {
            fireSpotLetter= fireSpotLetter - 97;
         }
      }
     else
     {
      cout << "Error! Try Again!";
      }
    }
    while(canBeFired == false);
}
