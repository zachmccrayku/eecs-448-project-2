#ifndef SHIP_H
#define SHIP_H

#include <iostream>
using namespace std;

class Ship
{
  public:
    Ship(); //sets m_ship, m_hasBeenHit to false, m_isHorizontal to true, gridChar to '_'
    ~Ship(); //deletes ship

    char gridChar; //changes to ^ when it is placed, changes to X when it is hit

    bool m_isShip; // does this coordinate contain a ship
    bool m_hasBeenHit; // has this spot been hit
    bool m_isHorizontal; // horizontal or vertical placement

    void placeShip(); //checks if it is a ship, if not makes is_ship true
    void hitShip(); //marks the ship as hit
    void isSunk(); //checks to see if the ship has been sunk
    void makeHorizontal(); //changes state of m_isHorizontal 
};

#endif
