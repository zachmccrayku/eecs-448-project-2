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
            gridChar = '^';
          }
      }
  }
}

void Ship::hitShip()
{
    if(m_isShip == true && m_hasBeenHit == false)
    {
        gridChar = 'X';
        m_hasBeenHit = true;
     }
}

void Ship::makeHorizontal()
{
  if(isHorizontal == true)
  {
    isHorizontal = false;
  }
  else
  {
    isHorizontal = true;
  }
}
