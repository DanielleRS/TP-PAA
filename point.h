#ifndef POINT_H
#define POINT_H

class Point
{
  public:
    Point();
    double getX();
    void setX(double);
    double getY();
    void setY(double);

  private:
    double x;
    double y;
    bool selected;
};

#endif // POINT_H
