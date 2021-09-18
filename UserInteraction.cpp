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
  do
  {
    cout << "Input the number of ships you wish to play with (1-6): ";
    numShips = isInteger();

    if (numShips < 1 || numShips > 6)
    {
      cout << "ERROR: Enter a number between 1 and 6.\n\n";
    }
  } while(numShips < 1 || numShips > 6);

  system("clear");
  cout << "Player 1 place your ships! [A-J][1-9]\n";
  player1->shipPlacement(numShips);

  system("clear");
  cout << "Player 2 place your ships! [A-J][1-9]\n";
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

        if (player1->checkWin()==true)
        {
          cout << "Player 1 wins!!";
          break;
        }
      }

      else
      {
        player1->fireAt();

        if (player2->checkWin() == true)
        {
          cout << "Player 2 wins!!";
          break;
        }
      }

      p1Turn = !p1Turn;
      system("clear");
    }

    if(choose == 2)
    {
      p1Turn ? player1->viewBoard() : player2->viewBoard();
    }

    if(choose == 3)
    {
      p1Turn ? player2->viewOBoard() : player1->viewOBoard();
    }

    if(choose == 4)
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

  do {
    p1Turn = true;
    cout << "Hi! Welcome to Battleship!\n";
    cout << "1. Start" << endl; // start the game
    cout << "2. Quit" << endl; //quit the game
    cout << "Option: ";
    choice = isInteger();

    if (choice == 1)
    {
      cout << "***************************\n";
      cout << "Game is starting...\n";
      cout << "***************************\n";

      playGame();
    }

    else if (choice == 2) // if quit
    {
      cout << "\nGoodbye!\n\n";
    }

    if(choice<1 || choice>2)
    {
      cout << "Please enter 1 to start a game or 2 to quit.\n"<< endl;
    }

  } while (choice<1 || choice>2);

}
