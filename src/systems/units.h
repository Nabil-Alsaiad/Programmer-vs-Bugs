#ifndef UNITS_H
#define UNITS_H

#pragma once

#include <cmath>
#include <vector>
#include <string>
#include "point.h"
#include "../units/unit.h"
#include "../units/unitstype.h"

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
    Stats generateRandomStats() const;
    Point attackClosestEnemy(Point &attackerPosition);

    Unit getPlayer() const;
    vector<Unit> getEnemies() const;

    Unit *getPlayerPointer();
    vector<Unit> *getEnemiesPointer();

    UnitsType getPlayerType() const;
    UnitsType getEnemiesType() const;
};

#endif