#ifndef SHIP_H
#define SHIP_H

#include <iostream>
using namespace std;

class Ship
{
  public:
    Ship();
    ~Ship();

    bool isHorizontal(); // horizontal or vertical placement
    bool hasBeenHit(); // has this spot been hit
    bool isShip(); // does this coordinate contain a ship

};

#endif
