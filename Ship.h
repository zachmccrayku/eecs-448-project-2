#ifndef SHIP_H
#define SHIP_H

#include <iostream>
using namespace std;

class Ship
{
  public:
    Ship();
    ~Ship();

    char gridChar;

    bool m_isShip; // does this coordinate contain a ship
    bool m_hasBeenHit; // has this spot been hit
    bool m_isHorizontal; // horizontal or vertical placement

    void placeShip(); //checks if it is a ship, if not makes is_ship true
    void hitShip(); //marks the ship as hit

};

#endif
