#include "Ship.h"
#include "Board.h"
#include "Gameplay.h"
#include <iostream>

using namespace std;

Ship::Ship()
{

}

bool Ship::isHorizontal()
{
    if (isHorizontal == true)
    {
        for(int i = 0; i < Shipsize; i++)
		{
			columns[i] = charValue + i; // refers to the letters on the board, both variables need to be established in gameplay
			row[i] = number; // refers to the number on  the board
        }
    }
    else if (isHorizontal == false)
    {
        for(int i = 0; i < Shipsize; i++)
        {
            columns[i] = charValue; 
			row[i] = number +i; 
        }
    }   
} 

bool Ship::hasBeenHit(char charValue, int number)
{
    for(int i = 0; i < Shipsize; i++)
	{

		if(charValue == column[i] && number == row[i])
		{
			return(true); //returns true if ship is located at the column and row specified
		}
	}
	return(false); //returns false if no ship present
}

bool Ship::isShip(char charValue, int number)
{
    for(int i = 0; i < Shipsize; i++)
	{

		if(charValue == column[i] && number == row[i])
		{
            cout << "There is already a ship here" << endl;
			return(true); //returns true if ship is located at the column and row specified
		}
	
        else
        {
	    cout << "This is an empty space" << endl;
        return(false); //returns false if no ship present
        }
    }
}
// as of now both isShip and hasBeenHit contain pretty much the same code