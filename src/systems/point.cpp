#include "point.h"
#include <iostream>

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

std::string Point::toString() const
{
    std::string xString = std::to_string(this->x);
    std::string yString = std::to_string(this->y);
    return "(" + xString + ", " + yString + ")";
}
