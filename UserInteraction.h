#ifndef USERINTERACTION_H
#define USERINTERACTION_H

#include "Board.h"
#include "GamePlay.h"
#include <iostream>
using namespace std;

class UserInteraction
{
private:
  Board* player1Board;
  Board* player2Board;
  GamePlay choice;

public:
  UserInteraction(); // initialize a board for each player
  ~UserInteraction(); // avoid memory leaks!
  void playGame(); // run calls play game, this is where it all runs
  void run(); // is called from main.cpp

  void viewBoard(); // can show attacks sent to enemy board, or players own board
  void shipPlacement(int numShips); // place ships onto board

};

#endif
