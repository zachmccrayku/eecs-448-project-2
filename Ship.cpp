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
  if (m_isShip == false)
  {
    m_isShip = true;
    gridChar = '^';
  }
}

void Ship::hitShip()
{
  if(m_isShip == true && m_hasBeenHit == false)
  {
    m_hasBeenHit = true;
    gridChar = 'X';
  }
}

void Ship::makeHorizontal(bool isHorizontal)
{
  if (isHorizontal)
  {
    m_isHorizontal = true;
  }

  else
  {
    m_isHorizontal = false;
  }
}
