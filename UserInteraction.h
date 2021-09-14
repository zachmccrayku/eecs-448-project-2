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
  int numShips;

public:
  UserInteraction(); // initialize a board for each player
  ~UserInteraction(); // avoid memory leaks!
  void playGame(); // run calls play game, this is where it all runs
  void run(); // is called from main.cpp
  void viewBoard();
  void shipPlacement(Board* tempBoard);
};

#endif
