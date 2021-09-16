  /**
   File Name: GamePlay.h
   Authors: Regan Janssen, Andrew Loaiza, Chen Lu, Jui Nagarkar, Natasha Shirley
   Description: Gameplay class allows users to attack, verify if ship is sunk, and end the game
   Date: Sept. 19, 2021
   */ 

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include<string>
using namespace std;

class GamePlay
{
private:

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
  string fireAt(); 

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
};

#endif
