#include "UserInteraction.h"

int main()
{
  UserInteraction letsPlay;
  letsPlay.run();

  return(0);
}
void run()
{
  while(1)
  {
    int choice;
    cout << "1. Start" << endl; // start the game and setting 
    //cout << "2. Setting" << endl;
    cout << "2. Quit" << endl;
    cin >> choice;
    if(choice ==1)
    { 
      letsPlay();
    }
    if(choice ==2)
    { 
      break;
    }
    if(choice<0 || choice>2)
    {
      cout << "Please enter the correct number to start a game or quit!"<< endl;
    }
  }
}  