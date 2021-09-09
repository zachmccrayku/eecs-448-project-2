/**
  File Name: Ship.h
  Authors: Regan Janssen, Andrew Loaiza, Chen Lu, Jui Nagarkar, Natasha Shirley
  Description: Ship class determines whether a ship has been hit, the class stores the ships location 
  Date: Sept. 19, 2021
  */ 

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
