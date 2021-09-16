#include "GamePlay.h"

GamePlay::GamePlay()
{
  canBeFired = false;
}

GamePlay::~GamePlay(){}

void GamePlay::fireAt(Board* CurrentBoard)
{
  // do
  // {
  //   cout << "Where would you like to fire?";
  //   cin >> fireAtSpot;
  //   convertString(fireAtSpot);
  //  if(fireSpotNum >= 49 || fireSpotNum <= 57)
  //   {
  //     fireSpotNum = fireSpotNum - 49;
  //       if(fireSpotLetter >= 65 || fireSpotLetter <= 74)
  //       {
  //         fireSpotLetter= fireSpotLetter - 65;
  //         
  //         }
  //       else if(fireSpotLetter >= 97 || fireSpotLetter <= 106)
  //       {
  //          fireSpotLetter= fireSpotLetter - 97;
  //       }
  //   }
   //       if(currentBoard[fireSpotNum][fireSpotLetter].getChar() == "_")
  //       {
  //          canBeFired==True;
  //       }
  //     
  //   
  //   else
  //   {
  //     cout << "Error! Try Again!";
  //    }
  //    
 //
  //  }
  //    while(canBeFired == false);
  //  CurrentBoard[i][j].hitShip();
  //

}

bool GamePlay::isSunk()
{
  // determine if ship that was just hit has been sunk
}

bool GamePlay::quitGame()
{
  //
  // cout << "Would you like to quit the game? Y/N";
  // cin >> choice;
  // if (choice == 'y' || choice == 'Y')
  // {
  // return(true);
  // }
  // else
  // {
  //   return(false);
  // }
}

int GamePlay::convertString(string temp)
{
  // fireSpotLetter = int(temp.at(0));
  //
  // fireSpotNum = int(temp.at(1));
}
