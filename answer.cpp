#include "answer.h"

Answer::Answer()
{

}

Answer::Answer(Point p1, Point p2, double distance)
{
  this->p1 = p1;
  this->p2 = p2;
  this->distance = distance;
}

double Answer::getDistance()
{
  return this->distance;
}

void Answer::setDistance(double distance)
{
  this->distance = distance;
}

Point Answer::getP1()
{
  return this->p1;
}

Point Answer::getP2()
{
  return this->p2;
}
