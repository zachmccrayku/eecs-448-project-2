#include "UserInteraction.h"

UserInteraction::UserInteraction()
{
  player1Board = new Board();
  player2Board = new Board();
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
      player1Board->viewBoard();
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
