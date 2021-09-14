#include "Ship.h"

Ship::Ship()
{
  gridChar = '_';
  m_isShip = false;
  m_hasBeenHit = false;
  m_isHorizontal = true;
}

Ship::~Ship(){}

void Ship::placeShip()
{
  m_isShip = false;
  for{int row=0; row<=9;row++}
  {
      for(int col=0; col<=9; col++)
      {
          if(m_ship == false)
          {
            m_isShip = true;
          }
      }
  }
}

void Ship::hitShip()
{
  m_hasBeenHit = false;
  for{int row=0; row<=9;row++}
  {
      for(int col=0; col<=9; col++)
      {
          //check ship 
          //if();
          //m_hasBeenHit = true
      }
  }  
}

void Ship::makeVertical()
{
  m_isHorizontal = false;
}
