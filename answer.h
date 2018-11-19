#ifndef ANSWER_H
#define ANSWER_H

#include "point.h"

class Answer
{
  public:
    Answer();
    Answer(Point, Point, double);
    double getDistance();
    void setDistance(double);
    Point getP1();
    Point getP2();

  private:
    Point p1;
    Point p2;
    double distance;
};

#endif // ANSWER_H
