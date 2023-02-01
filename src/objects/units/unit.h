#ifndef UNIT_H
#define UNIT_H

#pragma once

#include "stats.h"
#include "unitstype.h"
#include <string>

using namespace std;

class Unit
{
private:
    const UnitsType *TYPE_P;
    Stats stats_;
    int index_;

public:
    Unit();
    Unit(const UnitsType &type, const Stats &stats, const int index);
    string toString() const;
};

#endif