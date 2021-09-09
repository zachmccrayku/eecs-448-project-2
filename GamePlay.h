/**
  File Name: GamePlay.h
  Authors: Regan Janssen, Andrew Loaiza, Chen Lu, Jui Nagarkar, Natasha Shirley
  Description: Gameplay class allows users to attack, verify if ship is sunk, and end the game
  Date: Sept. 19, 2021
  */ 

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

using namespace std;

class GamePlay
{
private:

public:
  GamePlay();
  // a function to convert user's B2 to 1,1 (array indexes/coordinates)
  string fireAt(); // user chooses coordinates to shoot at
  bool isSunk(); // did opponents ship sink
  bool quitGame(); // end game command
};

#endif
