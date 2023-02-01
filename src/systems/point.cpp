#include "point.h"
#include <iostream>

using namespace std;

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

string Point::toString() const
{
    string xString = to_string(this->x);
    string yString = to_string(this->y);
    return "(" + xString + ", " + yString + ")";
}
