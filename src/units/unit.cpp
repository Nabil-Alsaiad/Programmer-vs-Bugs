#include "unit.h"

Unit::Unit()
{
}

Unit::Unit(const UnitsType &type, const Stats &stats, const Point position, const int index)
{
    TYPE_P = &type;
    this->stats = stats;
    this->position = position;
    this->index = index;
}

string Unit::toString() const
{
    string typeName = TYPE_P->getName();
    int spaceLeft = 11 - typeName.length();

    string space = " ";
    for (int i = 1; i < spaceLeft; ++i)
    {
        space += " ";
    }

    string identifier = typeName + space + to_string(index + 1);
    string location = position.toString();
    return identifier + " " + location + " - " + stats.toString();
}