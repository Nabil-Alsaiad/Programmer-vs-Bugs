#ifndef ROUNDS_H
#define ROUNDS_H

#pragma once

#include "board.h"
#include "units.h"

class Rounds
{
private:
    int gameRound_ = 1;

public:
    Rounds();

    bool isPlayerRound(const Units &units);
    void drawRoundBoard(const Units &units);

    // void playRound(Board &board, const Units &units);
    void playRound(const Units &units);
    void resetRound();
};

#endif