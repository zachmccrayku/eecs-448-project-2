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
    cout << "1. Start" << endl; // start the game
    cout << "2. Quit" << endl; //quit the game
    cin >> choice;
    if(choice == 1)
    {
      cout << "***************************\n";
      cout << "Game is starting...\n";
      cout << "***************************\n";
      

      cout << "input your number of ships (enter a value between 1-6): ";
      cin >> numShips;
      do
      {
        cout << "Sorry, the value entered was not between the allowed value. Please try again.";
        cout << "input your number of ships (enter a value between 1-6): ";
        cin >> numShips;
      }
      while(numShips > 6 || numShips <=0);
      

     cout << "Player 1 where you like to set your ship?\n";
      player1->shipPlacement(numShips);
     cout << "Player 2 where you like to set your ship\n";
      player2->shipPlacement(numShips);

    while(numShips != isSunk)   
      {
       int choose;
        
       cout << "1. Attack opponent\n"; 
       cout << "2. View my board\n"; 
       cout << "3. View opponent board\n"; 
       cout << "4. Quit\n"; 
       cout << "What would you like to do: \n";
        cin >> choose;
        do
        {
          cout << "Sorry, the value entered was not between the allowed value. Please try again.\n";
          
          cout << "1. Attack opponent\n"; 
          cout << "2. View my board\n"; 
          cout << "3. View opponent board\n"; 
          cout << "4. Quit\n"; 
          cout << "What would you like to do: \n"; 
          cin >> choose;
        } while(choose <= 0 || choose > 4);
        

       if(choose == 1)
       {
         fireAt();
       }

       if(choose == 2)
       {
          if(player1 == true)
          {
            player1->viewBoard;
          }
          else
          {
            player2->viewBoard2;
          }
       }

       if(choose == 3)
       {
          if(player1 == true)
          {
            player1->viewOBoard;
          }
          else
          {
            player2->viewOBoard2;
          }
       }
       if(choose == 4)
       {
         cout << "Quitting...";
         break;
       }
      }

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
