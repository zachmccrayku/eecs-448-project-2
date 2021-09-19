/**
File Name: Board.cpp
Authors: Regan Janssen, Andrew Loaiza, Chen Lu, Jui Nagarkar, Natasha Shirley
Description: UserInteraction for main gameplay is defined in the UserInteraction class, acts as the executive class
Date: Sept. 19, 2021
*/

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


int UserInteraction::isInteger()
{
  // prompt user for option
  int option = 0;
  cin >> option;

  // from wiki for bad input
  while (cin.fail())
  {
   cin.clear(); // unset failbit

   // skip bad input up to the next newline
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   cout << "ERROR: Your intput did not seem to be a number. Try again: ";
   cin >> option;
  }

  // flush out anything left in the stream
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  return(option);
}


void UserInteraction::playGame()
{
  //within the playGame we have the do loop which asks the player to input the number of ships in the game
  //here if the number of ships is less than 1 or greater than 6 
  //it returns an error telling the player to enter a number between 1 and 6
  do
  {
    cout << "Input the number of ships you wish to play with (1-6): ";
    numShips = isInteger();

    if (numShips < 1 || numShips > 6) //if numShips <1 or >6 return error message prompting to enter correct value
    {
      cout << "ERROR: Enter a number between 1 and 6.\n\n";
    }
  } while(numShips < 1 || numShips > 6);

  system("clear");
  cout << "Player 1 place your ships! [A-J][1-9]\n"; //asks player 1 to place the ships
  player1->shipPlacement(numShips);

  system("clear");
  cout << "Player 2 place your ships! [A-J][1-9]\n"; //asks player 2 to place the ships
  player2->shipPlacement(numShips);

  while(1)
  {
    int choose;

    do
    {
      p1Turn ? cout << "Player 1's turn\n\n" : cout << "Player 2's turn\n\n";
      cout << "1. Attack opponent\n";
      cout << "2. View my board\n";
      cout << "3. View my attacks to opponent\n";
      cout << "4. Quit\n";
      cout << "What would you like to do: ";
      choose = isInteger();

      if (choose < 1 || choose > 4)
      {
        cout << "ERROR: Invalid menu option. Try again.\n\n";
      }
    } while(choose < 1 || choose > 4);


    if(choose == 1)
    {
      if(p1Turn)
      {
        player2->fireAt();

        if (player2->hasLost())
        {
          cout << "\nPlayer 1 wins!!\n\n";
          break;
        }
      }

      else
      {
        player1->fireAt();

        if (player1->hasLost())
        {
          cout << "\nPlayer 2 wins!!\n\n";
          break;
        }
      }

      p1Turn = !p1Turn;
      system("clear");
    }

    if(choose == 2) //if 2 then the players get to view their own board
    {
      p1Turn ? player1->viewBoard() : player2->viewBoard();
    }

    if(choose == 3) //if 3 then the players get to view their oppoent's board
    {
      p1Turn ? player2->viewOBoard() : player1->viewOBoard();
    }

    if(choose == 4) //if 4 then quits
    {
      cout << "Quitting...\n";
      break;
    }

  } // end of loop

  cout << "Goodbye!\n\n";
}


void UserInteraction::run()
{
  int choice;
  //within the run, we have a do loop that welcomes the players and gives the menu to either start the game or quit
  //the players can choose 1 or 2. If they enter any other value other than this it tells the player to enter the valid number.
  do {
    p1Turn = true;
    cout << "Hi! Welcome to Battleship!\n";
    cout << "1. Start" << endl; // start the game
    cout << "2. Quit" << endl; //quit the game
    cout << "Option: ";
    choice = isInteger();

    if (choice == 1) //if 1 then the game starts
    {
      cout << "***************************\n";
      cout << "Game is starting...\n";
      cout << "***************************\n";

      playGame();
    }

    else if (choice == 2) // if 2 then quits the game
    {
      cout << "\nGoodbye!\n\n";
    }

    if(choice<1 || choice>2) // if anything other than 1 or 2 it prompts the question again to enter valid input.
    {
      cout << "Please enter 1 to start a game or 2 to quit.\n"<< endl;
    }

  } while (choice<1 || choice>2); //do loop runs while the the entered value is not less than 1 or greater than 2.

}
