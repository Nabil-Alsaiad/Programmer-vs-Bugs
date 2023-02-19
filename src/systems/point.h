#ifndef POINT_H
#define POINT_H

#pragma once

#include <string>

using namespace std;

struct Point
{
public:
    int x, y;
    Point(int x = -1, int y = -1);
    string toString() const;

    bool isEqual(const Point pointToCompare) const;
    bool isNull() const;
};

#endif
