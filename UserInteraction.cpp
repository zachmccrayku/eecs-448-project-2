#include "UserInteraction.h"

UserInteraction::UserInteraction()
{
  player1 = new Board();
  player2 = new Board();
  numShips = 0;
}


UserInteraction::~UserInteraction()
{
  delete player1;
  delete player2;
}


void UserInteraction::playGame()
{
  // main code goes here

  while(1)
  {
    int choice;
    cout << "Hi! Welcome to Battleship!\n";
    cout << "1. Start" << endl; // start the game and setting
    //cout << "2. Setting" << endl;
    cout << "2. Quit" << endl;
    cin >> choice;
    if(choice == 1)
    {
      cout << "***************************\n";
      cout << "Game is starting...\n";
      cout << "***************************\n";
      

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

     cout << "Player 1 where you like to set your ship?\n";
      player1.shipPlacement(numShips);
     cout << "Player 2 where you like to set your ship\n";
      player2.shipPlacement(numShips);

          
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
