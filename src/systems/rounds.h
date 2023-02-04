#ifndef ROUNDS_H
#define ROUNDS_H

#pragma once

#include "board.h"
#include "units.h"

class Rounds
{
private:
    Units *units_p;
    int gameRound_ = 1;

public:
    Rounds();
    Rounds(Units *units);

    bool isPlayerRound();
    void drawRoundBoard();

    // void playRound(Board &board, const Units &units);
    void increaseRound();
    void resetRound();
};

#endif