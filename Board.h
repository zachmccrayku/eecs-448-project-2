#ifndef BOARD_H
#define BOARD_H
#include "Ship.h"
#include "ViewBoard.h"
/* include grid and other h files*/
#include <iostream>
using namespace std;

class Board
{
    public:
        Board::~Board();

        Ships setShip();

        void printBoard();





};
#endif