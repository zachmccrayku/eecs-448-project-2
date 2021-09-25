#include "Ship.h"

Ship::Ship()
{
  m_char = ' ';
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
    m_char = '#';
  }
}

bool Ship::hitShip()
{
  bool hitSpot = false;

  // Hit
  if(m_isShip == true && m_hasBeenHit == false)
  {
    m_hasBeenHit = true;
    m_char = '*';
    hitSpot = true;
  }

  // Missed
  if (m_isShip == false && m_hasBeenHit == false)
  {
    m_hasBeenHit = true;
    m_char = '.';
    hitSpot = true;
  }

  // if spot has already been hit, return false (they must redo attempt)
  return hitSpot;
}

void Ship::setOrientation(bool isHorizontal)
{
  m_isHorizontal = isHorizontal;
}

bool Ship::isHorizontal()
{
  return(m_isHorizontal);
}

char Ship::getChar()
{
  return(m_char);
}

bool Ship::hasBeenHit()
{
  return(m_hasBeenHit);
}

bool Ship::isShip()
{
  return(m_isShip);
}
