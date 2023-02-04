#ifndef UNIT_H
#define UNIT_H

#pragma once

#include "../systems/point.h"
#include "stats.h"
#include "unitstype.h"
#include <string>

using namespace std;

class Unit
{
private:
    const UnitsType *TYPE_P;
    Stats stats_;
    Point position_;
    int index_;

public:
    Unit();
    Unit(const UnitsType &type, const Stats &stats = Stats(100, 10, 0), const Point position = Point(0, 0), const int index = 0);
    string toString() const;

    Point getPosition() const;
    void setPosition(const Point position);
};

#endif