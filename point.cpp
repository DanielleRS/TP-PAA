#include "point.h"

Point::Point()
{
  this->selected = false;
}

double Point::getX()
{
  return this->x;
}

void Point::setX(double x)
{
  this->x = x;
}

double Point::getY()
{
  return this->y;
}

void Point::setY(double y)
{
  this->y = y;
}
