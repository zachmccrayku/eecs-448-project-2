/**
File Name: Board.h
Authors: Regan Janssen, Andrew Loaiza, Chen Lu, Jui Nagarkar, Natasha Shirley
Description: Board class creates grid and places the location of the ship. Allows players to view the board
Date: Sept. 19, 2021
*/

#ifndef BOARD_H
#define BOARD_H

#include <cstdlib>
#include <limits>
#include "Ship.h"

using namespace std;

class Board
{
private:
  int numRows = 9; // Sets the number of rows for the board
  int numCols = 10; // Sets the number of columns for the board
  Ship m_grid[9][10]; // 2D array of type Ship
  // char m_oppGrid[9][10]; // 2D array of char, this is what opponent will view
  int m_row;
  int m_col;
  int m_numShips;
  int m_shipsSunk;
  string fireAtSpot;
  bool canBeFired;

public:
  /*
  *Initializes a 9x10 board
  *@param None
  */
  Board();

  ~Board(); // avoid memory leaks!

  /*
  *Allows players to view their board as well as the opponents board with their hits and misses
  *@param None
  */
  void viewBoard();

    /*
  *Allows players to view other player's board as well as the opponents board with their hits and misses
  *@param None
  */
  void viewOBoard();

  /*
  *Ship is placed on the board
  *@param number of ships
  */
  void shipPlacement(int numShips);

  /*
  *Converts string input to int, checks for out of bounds
  *@param string
  *@return int value
  */
  void convertCoord();

  /*
  *User chooses coordinates to shoot at
  *@param None
  *@returns the coordinate of the shot
  */
  void fireAt();

  /*
  *Checks to see if the opponents ship sunk
  *@param None
  *@return boolean value for ship status
  */
  bool isSunk(int row, int col);


  /*
  *Checks to see if all ships have been sunk
  *@param None
  *@return boolean value for win status
  */
  bool checkWin();

};

#endif
