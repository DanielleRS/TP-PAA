#include <algorithm>
#include <vector>
#include <cmath>
#include <cfloat>

#include "util.h"

void readPoints(vector<Point>* points)
{
  int numberOfPoints;
  double x;
  double y;
  Point point;

  cin >> numberOfPoints;

  for (int i = 0; i < numberOfPoints; i++)
  {
    cin >> x;
    cin >> y;

    point.setX(x);
    point.setY(y);

    points->push_back(point);
  }
}

Answer exhaustiveMethod(vector<Point>* points, int begin, int end)
{
  int indexP1, indexP2;
  double smallestDistance = DBL_MAX;
  double currentDistance;

  for (int i = begin; i < end - 1; i++)
  {
    for (int j = i + 1; j < end; j++)
    {
      currentDistance = euclideanDistance(points->at(i), points->at(j));

      if (smallestDistance > currentDistance)
      {
        smallestDistance = currentDistance;
        indexP1 = i;
        indexP2 = j;
      }
    }
  }

  Answer answer(points->at(indexP1), points->at(indexP2), smallestDistance);

  return answer;
}

double euclideanDistance(Point a, Point b)
{
  return sqrt(pow((a.getX() - b.getX()), 2) + pow((a.getY() - b.getY()), 2));
}

bool compareX(Point a, Point b)
{
  return a.getX() < b.getX();
}

Answer divideAndConquerMethod(vector<Point>* points)
{
  vector<Point> x = *points;

  // Generates arrays sorted by x and y coordinates
  sort(x.begin(), x.end(), compareX);

  return recursiveStep(points, 0, points->size(), &x);
}

Answer recursiveStep(vector<Point>* points, int lp, int rp,
                        vector<Point>* x)
{
  int half = (lp + rp) / 2;

  if (rp - lp <= 3)
  {
    return exhaustiveMethod(points, lp, rp);
  }
  else
  {
    Answer leftAnswer, rightAnswer, answer;

    leftAnswer = recursiveStep(points, lp, half, x);
    rightAnswer = recursiveStep(points, half, rp, x);

    if (leftAnswer.getDistance() < rightAnswer.getDistance())
      answer = leftAnswer;
    else
      answer = rightAnswer;

    //candidadtes
    vector<Point> candidates;

    candidates.push_back(x->at(half));

    //right side
    for (int i = half + 1; i < rp; i++)
      if (fabs(x->at(half).getX() - x->at(i).getX()) < answer.getDistance())
        candidates.push_back(x->at(i));

    //left side
    for (int i = half - 1; i >= lp; i--)
      if (fabs(x->at(half).getX() - x->at(i).getX()) < answer.getDistance())
        candidates.push_back(x->at(i));

    Answer candidatesAnswer;

    candidatesAnswer.setDistance(DBL_MAX);

    if (candidates.size() > 1)
      candidatesAnswer = exhaustiveMethod(&candidates, 0, candidates.size());

    if (candidatesAnswer.getDistance() < answer.getDistance())
      return candidatesAnswer;
    else
      return answer;
  }
}
