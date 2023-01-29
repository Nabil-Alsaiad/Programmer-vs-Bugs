#ifndef POINT_H
#define POINT_H

#include <string>

struct Point
{
public:
    int x, y;
    Point(int x = 0, int y = 0);
    std::string toString() const;
};

#endif