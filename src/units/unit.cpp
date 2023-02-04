#ifndef UNIT_CPP
#define UNIT_CPP

#pragma once

#include "unit.h"
#include <string>

using namespace std;

Unit::Unit()
{
}

Unit::Unit(const UnitsType &type, const Stats &stats, const Point position, const int index)
{
    TYPE_P = &type;
    stats_ = stats;
    position_ = position;
    index_ = index;
}

string Unit::toString() const
{
    string identifier = TYPE_P->getName() + " " + to_string(index_ + 1) + " : ";
    return identifier + stats_.toString();
}

Point Unit::getPosition() const
{
    return position_;
}

void Unit::setPosition(const Point position)
{
    position_ = position;
}

#endif