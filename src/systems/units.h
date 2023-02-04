#ifndef UNITS_H
#define UNITS_H

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "../units/unit.cpp"
#include "../units/unitstype.cpp"

using namespace std;

class Units
{
private:
    Unit player_;
    vector<Unit> enemies_;

    UnitsType playersType_;
    UnitsType enemiesType_;

public:
    Units(int enemyCount = 2);

    void fillUnits(Point boardCenter, vector<Point> randomPoints);
    int getRandomHealth();

    Unit getPlayer() const;
    vector<Unit> getEnemies() const;

    UnitsType getPlayerType() const;
    UnitsType getEnemiesType() const;
};

#endif