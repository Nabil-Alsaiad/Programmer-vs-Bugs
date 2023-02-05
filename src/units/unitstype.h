#ifndef UNITS_TYPE_H
#define UNITS_TYPE_H

#pragma once

#include <string>

using namespace std;

class UnitsType
{
private:
    string name_;
    char symbol_;
    int count_;

public:
    UnitsType(string name = "name", char symbol = ' ', int count = 1);

    string getName() const;
    char getSymbol() const;
    int getCount() const;
};

#endif