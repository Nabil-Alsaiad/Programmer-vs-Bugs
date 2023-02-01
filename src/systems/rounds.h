#ifndef ROUNDS_H
#define ROUNDS_H

#pragma once

class Rounds
{
private:
    int gameRound_ = 1;

public:
    Rounds();

    void resetRound();
    bool isPlayerRound(const Units &units);
    void drawRoundBoard(const Units &units);
};

#endif