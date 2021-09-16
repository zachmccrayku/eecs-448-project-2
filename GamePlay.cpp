#include "GamePlay.h"

GamePlay::GamePlay()
{
  canBeFired = false;
}

GamePlay::~GamePlay(){}

int GamePlay::fireAt()
{
  do
  {
    cout << "Where would you like to fire?";
    cin >> fireAtSpot;
    convertString(fireAtSpot);
   if(fireSpot1 >= 65 || fireSpot1 <= 74)
     {
       fireSpot1= fireSpotLetter - 66;
       canBeFired = true;
     }
    else if(fireSpotNum >= 1 || fireSpotNum <= 10)
    {
      fireSpotNum = fireSpotNum - 1;
      canBeFired = true;
    }
    else
    {
      cout << "Error! Location Does Not Exist! Try Again!";
     }
   }
     while(canBeFired == false);
    return(fireSpotLetter, fireSpotNum);
  
}

bool GamePlay::isSunk()
{
  // determine if ship that was just hit has been sunk
}

bool GamePlay::quitGame()
{ 
  
  cout << "Would you like to quit the game? Y/N";
  cin >> choice;
  if (choice == 'y' || choice == 'Y')
  {
  return(true);
  }
  else 
  {
    return(false);
  }
}

int GamePlay::convertString(string temp)
{
  fireSpotLetter = int(temp.at(0));
 
  fireSpotNum = int(temp.at(1)); 
}
