#ifndef POINT_H
#define POINT_H

#pragma once

#include <string>

using namespace std;

struct Point
{
public:
    int x, y;
    Point(int x = 0, int y = 0);
    string toString() const;
};

#endif
