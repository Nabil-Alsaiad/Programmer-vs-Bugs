#ifndef ROUNDS_H
#define ROUNDS_H

#pragma once

#include <iostream>
#include <vector>
#include "units.h"
#include "movement.cpp"

using namespace std;

class Rounds
{
private:
    int playerRound_ = 0;
    int gameRound_ = playerRound_;

public:
    Rounds();

    bool shouldResetRound(const Units &units);
    void increaseRound();

    bool isPlayerRound() const;
    int getEnemyRoundIndex() const;

    bool playEnemyRound(Board &board, Unit *player_p, Unit *enemy_p) const;
    void drawUnitsBoard(const Units &units, bool drawArrow = true) const;
};

#endif