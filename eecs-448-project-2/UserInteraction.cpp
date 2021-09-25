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


int UserInteraction::promptForInt(int min, int max)
{
  // Prompt user for option
  int input = 0;

  while(true) {
    cin >> input;

    // Unset failBit
    cin.clear();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if(cin.fail())
      cout << "ERROR: Your input did not seem to be a number. Try again.";

    else if(input < min || input > max)
      cout << "ERROR: Please enter a number in range from " << min << " to " <<  max << ".\n";

    else
      return input;
  };
}


void UserInteraction::playGame()
{
  cout << "Input the number of ships you wish to play with (1-6): ";
  numShips = promptForInt(1, 6);

  system("clear");
  cout << "Player 1 place your ships! [A-J][1-9]\n";
  player1->shipPlacement(numShips);

  system("clear");
  cout << "Player 2 place your ships! [A-J][1-9]\n";
  player2->shipPlacement(numShips);

  bool gameOver = false;
  while(!gameOver)
  {

    cout
     << "Player " << (p1Turn ? 1 : 2) << "'s turn\n\n"
     << "1. Attack opponent\n"
     << "2. View my board\n"
     << "3. View my attacks on the opponent\n"
     << "0. Quit\n";

    switch(promptForInt(0,4)){
      case 1:
        if(p1Turn)
        {
          player2->fireAt();

          if (player2->hasLost())
          {
            cout << "\nPlayer 1 wins!!\n\n";
            gameOver = true;
          }
        }

        else
        {
          player1->fireAt();

          if (player1->hasLost())
          {
            cout << "\nPlayer 2 wins!!\n\n";
            gameOver = true;
          }
        }

        p1Turn = !p1Turn;
        system("clear");
        break;
      case 2:
        if(p1Turn)
          player1->viewBoard();
        else
          player2->viewBoard();
        break;
      case 3:
        if(p1Turn)
          player2->viewOBoard();
        else
          player1->viewOBoard();
        break;
      case 0:
        gameOver = true;
        break;
    }

  }

}


void UserInteraction::run()
{

  p1Turn = true;
  cout
    << "Welcome to Battleship!\n"
    << "1. Start\n"
    << "0. Quit\n";

  if(promptForInt(0,1))
    playGame();
  else
    cout << "Goodbye!\n";

}
