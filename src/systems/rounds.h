#ifndef ROUNDS_H
#define ROUNDS_H

#pragma once

#include "board.h"
#include "units.h"

class Rounds
{
private:
    Units *units_p;
    int playerRound_ = 0;
    int gameRound_ = playerRound_;

public:
    Rounds();
    Rounds(Units *units);

    bool isPlayerRound();
    void drawRoundBoard();

    void increaseRound();
    void resetRound();
};

#endif