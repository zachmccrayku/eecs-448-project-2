#ifndef USERINTERACTION_H
#define USERINTERACTION_H

#include "Board.h"
#include "GamePlay.h"
#include <iostream>
using namespace std;

class UserInteraction
{
private:
  Board* player1Board; // Points to player 1 board
  Board* player2Board; // Points to player 2 board
  GamePlay choice; // Gives players the gameplay options
  int numShips; // Is given by user and sets up the number of ships for placement

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

  /*
   *Allows players to view their board as well as the opponents board with their hits and misses
   *@param None
   */
  void viewBoard();

  /*
   *Ship is placed on the board 
   *@param tempboard- allows for editing of player 1 and player 2 boards
   */
  void shipPlacement(Board* tempBoard);
};

#endif
