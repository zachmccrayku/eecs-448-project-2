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
  Board player1Board;
  Board player2Board;
  GamePlay choice;

public:
  UserInteraction(); // initialize a board for each player
  ~UserInteraction(); // avoid memory leaks!
  void playGame(); // run calls play game, this is where it all runs
  void run(); // is called from main.cpp
};

#endif
