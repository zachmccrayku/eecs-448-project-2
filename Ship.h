#ifndef SHIP_H
#define SHIP_H

#include <iostream>
using namespace std;

class Ship
{
  public:
   /*
   **Sets m_ship, m_hasBeenHit to false, m_isHorizontal to true, gridChar to '_'
   *@param None
   */
    Ship(); //sets m_ship, m_hasBeenHit to false, m_isHorizontal to true, gridChar to '_'

    ~Ship(); //deletes ship

    /*
	  **Changes to ^ when it is placed, changes to X when it is hit
	  *@param None
	  */
    char gridChar; //changes to ^ when it is placed, changes to X when it is hit

    /*
    **Checks to see whether or not the coordinate contains a ship
	  *@param None
    */
    bool m_isShip; // does this coordinate contain a ship

    /*
	  **Checks to see whether or not the ship has been hit 
	  *@param None
	  */
    bool m_hasBeenHit; // has this spot been hit

    /*
	  **Sets a ships placement to either horizontal or vertical
    *@param None
    */
    bool m_isHorizontal; // horizontal or vertical placement

    /*
	  **Checks if there is a ship, if not it makes is_ship true 
	  *@param None
	  */
    void placeShip(); //checks if it is a ship, if not makes is_ship true

    /*
	  **Marks the ship as hit
	  *@param None
	  */ 
    void hitShip(); //marks the ship as hit

    /*
	  **Checks to see if the ship has been sunk
	  *@param None
	  */ 
    void isSunk(); //checks to see if the ship has been sunk

    /*
	  **Changes state of m_isHorizontal 
	  *@param None
	  */ 
    void makeHorizontal(); //changes state of m_isHorizontal 
};

#endif
