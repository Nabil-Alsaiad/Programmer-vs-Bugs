#include "point.h"

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

string Point::toString() const
{
    string xString = to_string(x);
    string yString = to_string(y);

    if (xString.length() == 1)
    {
        xString = " " + xString;
    }

    if (yString.length() == 1)
    {
        yString = " " + yString;
    }

    return "(" + xString + ", " + yString + ")";
}

bool Point::isEqual(const Point pointToCompare) const
{
    return x == pointToCompare.x && y == pointToCompare.y;
}

bool Point::isNull() const
{
    return x < 0 && y < 0;
}
