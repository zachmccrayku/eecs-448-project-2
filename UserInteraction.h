  /**
   File Name: UserInteraction.h
   Authors: Regan Janssen, Andrew Loaiza, Chen Lu, Jui Nagarkar, Natasha Shirley
   Description: Acts as executive class for the game. Initializes players and boards and runs the game
   Date: Sept. 19, 2021
   */

#ifndef USERINTERACTION_H
#define USERINTERACTION_H

#include "Board.h"
#include "GamePlay.h"
#include <iostream>
using namespace std;

class UserInteraction
{
private:
  Board* player1; // Points to player 1 board
  Board* player2; // Points to player 2 board
  GamePlay choice; // Gives players the gameplay options
  int numShips; // Is given by user and sets up the number of ships for placement
  bool p1Turn;

public:
  /*
   *Initalizes a board for each player
   *@param None
   */
  UserInteraction();

  ~UserInteraction(); // avoid memory leaks!

  /*
   *Run function calls playgame which contains the main game functionality
   *@param None
   */
  void playGame();

  /*
   *Is called from main.cpp to start the game
   *@param None
   */
  void run();
};

#endif
