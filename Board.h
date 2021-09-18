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
  int m_row; //current row location
  int m_col; //current col location
  int m_numShips; //number of ships
  int m_shipsSunk; //number of ships that have been sunk
  string userInput; //string to store user input
  bool validInput; //true if valid
  string invalidCoordMessage; //stores error message

public:
  /*
  *Initializes a 9x10 board
  *@param None
  *@return none
  */
  Board();

  /*
  *deallocates the board object
  *@param None
  *@return none
  */
  ~Board(); // avoid memory leaks!

  /*
  *Allows players to view their board as well as the opponents board with their hits and misses
  *@param None
  *@return none
  */
  void viewBoard();

    /*
  *Allows players to view other player's board as well as the opponents board with their hits and misses
  *@param None
  *@return none
  */
  void viewOBoard();

  /*
  *Ship is placed on the board
  *@param number of ships
  *@return none
  */
  void shipPlacement(int numShips);

  /*
  *Converts string input to int, checks for out of bounds
  *@param none
  *@return none
  */
  void convertCoord();

  /*
  *Checks if ship placement is valid
  *@param int number for for loops and a bool for orientation
  *@return none
  */
  void checkValidShipPlacement(int shipSize, bool horizontal);

  /*
  *User chooses coordinates to shoot at
  *@param None
  *@returns none
  */
  void fireAt();

  /*
  *Checks to see if the opponents ship sunk
  *@param int for row and col location
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
