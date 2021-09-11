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
  m_isShip = true;
}

void Ship::hitShip()
{
  m_hasBeenHit = true;
}

void Ship::makeVertical()
{
  m_isHorizontal = false;
}
