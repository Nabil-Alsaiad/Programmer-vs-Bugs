#include "unitstype.h"

UnitsType::UnitsType(string name, char symbol, int count)
{
    name_ = name;
    symbol_ = symbol;
    count_ = count;
}

string UnitsType::getName() const
{
    return name_;
}

char UnitsType::getSymbol() const
{
    return symbol_;
}

int UnitsType::getCount() const
{
    return count_;
}
