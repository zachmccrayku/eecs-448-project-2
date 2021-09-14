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
    Ship(); 

    /*
    **Deletes ship
    *@param None
    */
    ~Ship(); 

    /*
	  **Changes to ^ when it is placed, changes to X when it is hit
	  *@param None
	  */
    char gridChar; 

    /*
    **Checks to see whether or not the coordinate contains a ship
	  *@param None
    */
    bool m_isShip; 

    /*
	  **Checks to see whether or not the ship has been hit 
	  *@param None
	  */
    bool m_hasBeenHit; 

    /*
	  **Sets a ships placement to either horizontal or vertical
    *@param None
    */
    bool m_isHorizontal; 

    /*
	  **Checks if there is a ship, if not it makes is_ship true 
	  *@param None
	  */
    void placeShip(); 

    /*
	  **Marks the ship as hit
	  *@param None
	  */ 
    void hitShip(); 

    /*
	  **Checks to see if the ship has been sunk
	  *@param None
	  */ 
    void isSunk(); 

    /*
	  **Changes state of m_isHorizontal 
	  *@param None
	  */ 
    void makeHorizontal();  
};

#endif
