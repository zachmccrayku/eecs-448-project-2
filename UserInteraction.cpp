#include "UserInteraction.h"

UserInteraction::UserInteraction()
{
  player1Board = new Board();
  player2Board = new Board();
  //player1Ship = new array [][];
  //player2Ship = new araay [][];
}


UserInteraction::~UserInteraction()
{
  delete player1Board;
  delete player2Board;
}


void UserInteraction::playGame()
{
  // main code goes here

  while(1)
  {
    int choice;
    cout << "1. Start" << endl; // start the game and setting
    //cout << "2. Setting" << endl;
    cout << "2. Quit" << endl;
    cin >> choice;
    if(choice == 1)
    {
      cout << "Game is starting...\n";
      cout << "***************************";
      cout << "Player 1";
      cout << "***************************";
      player1Board->viewBoard();
    
      cout << "input your number of ships (enter a value between 1-6): ";
      cin >> numShips;
      if(numShips > 6 || numShips <= 0)
      {
      do
      {
        cout << "Sorry, the value entered was not between the allowed value. Please try again.";
        cout << "input your number of ships (enter a value between 1-6): ";
        cin >> numShips;
      }
      while(numShips > 6 || numShips <=0);
      }
      int cout;
      cin >> cout;
      for(int k=1; k<=cout; k++)
      {
          //set each ship
          //if()
          cout << "Player 1 where you like to set your ship " + k  "input your col and row" ;
          //check ver
      }
      //after set player 1 and then go to player 2 
    }
    if(choice == 2)
    {
      break;
    }
    if(choice<1 || choice>2)
    {
      cout << "Please enter the correct number to start a game or quit!"<< endl;
    }
  }
}


void UserInteraction::run()
{
  playGame();
}


void UserInteraction::viewBoard()
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

  for (int i = 1; i <= m_numShips; i++)
  {

  }
}
