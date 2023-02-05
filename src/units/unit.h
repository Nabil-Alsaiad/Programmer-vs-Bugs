#ifndef UNIT_H
#define UNIT_H

#pragma once

#include <string>
#include "stats.h"
#include "unitstype.h"
#include "../systems/point.h"

using namespace std;

struct Unit
{
public:
    const UnitsType *TYPE_P;
    Stats stats;
    Point position;
    int index;

    Unit();
    Unit(const UnitsType &type, const Stats &stats, const Point position, const int index);
    string toString() const;
};

#endif