#ifndef ROUNDS_H
#define ROUNDS_H

#pragma once

#include <iostream>
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

    bool playEnemyRound(Board &board, Units &units) const;
    void drawRoundBoard(const Units &units) const;
};

#endif