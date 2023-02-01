#ifndef UNITS_H
#define UNITS_H

#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "../units/unit.cpp"
#include "../units/unitstype.cpp"
#include "board.h"

using namespace std;

class Units
{
private:
    vector<Unit> players_;
    vector<Unit> enemies_;

    UnitsType playersType_;
    UnitsType enemiesType_;

public:
    Units();

    void fillUnitsInBoard(Board &board);

    vector<Unit> getPlayers() const;
    vector<Unit> getEnemies() const;

    UnitsType getPlayersType() const;
    UnitsType getEnemiesType() const;
};

#endif