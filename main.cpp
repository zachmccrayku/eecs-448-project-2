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
    cout << "1. Start" << endl;
    cout << "2. Setting" << endl;
    cout << "3. Quit" << endl;
    cin >> choice;
    if(choice ==1)
    { 
      letsPlay();
    }
    if(choice ==2)
    { 
      setting();
    }
    if(choice ==3)
    {
      break;
    }
  }
}  