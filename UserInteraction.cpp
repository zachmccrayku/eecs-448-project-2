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
      cout << "input your number of ships ";
      int cout;
      cin >> cout;
      for(int k=0; k<=cout; k++)
      {
          //set each ship  
          //if()
          cout << "Player 1 what you like to set your ship input your col and row";
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
