#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include<string>
using namespace std;

class GamePlay
{
private:
  string fireAtSpot; 
  int fireSpotLetter; 
  int fireSpotNum;
  bool canBeFired;
  char choice; 

public:
  /*
  *Initializes Gameplay
  *@param None
  */
  GamePlay();
  ~GamePlay(); //avoid memory leaks!

  // a function to convert user's B2 to 1,1 (array indexes/coordinates)

  /*
  *User chooses coordinates to shoot at
  *@param None
  *@returns the coordinate of the shot
  */
  int fireAt(); 

  /*
  *Checks to see if the opponents ship sunk
  *@param None
  *@return boolean value for ship status
  */
  bool isSunk(); 

  /*
  *Command to end the game
  *@param None
  *@return boolean value 
  */
  bool quitGame(); 
  
    /*
  *Converts string input to int 
  *@param string
  *@return int value
  */
  int convertString(string temp);
};

#endif
