#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>

#include "point.h"
#include "answer.h"

using namespace std;

void readPoints(vector<Point>*);
Answer exhaustiveMethod(vector<Point>*, int, int);
double euclideanDistance(Point, Point);
bool compareX(Point, Point);
Answer divideAndConquerMethod(vector<Point>*);
Answer recursiveStep(vector<Point>*, int, int, vector<Point>*);

#endif // UTIL_H
