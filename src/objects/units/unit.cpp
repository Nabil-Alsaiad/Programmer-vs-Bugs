#include "unit.h"
#include <string>

using namespace std;

Unit::Unit()
{
}

Unit::Unit(const UnitsType &type, const Stats &stats, const int index)
{
    TYPE_P = &type;
    stats_ = stats;
    index_ = index;
}

string Unit::toString() const
{
    string identifier = TYPE_P->getName() + " " + to_string(index_) + " : ";
    return identifier + stats_.toString();
}
