#include <iostream>
#include <string>
#include "rounds.h"
#include "board.h"
#include "units.h"
#include "../pf/helper.h"
#include "../units/unit.cpp"

using namespace std;
using namespace pf;

Rounds::Rounds()
{
    resetRound();
}

Rounds::Rounds(Units *units)
{
    units_p = units;
    Rounds();
}

void Rounds::increaseRound()
{
    gameRound_++;
}

void Rounds::resetRound()
{
    gameRound_ = playerRound_;
}

bool Rounds::isPlayerRound()
{
    return gameRound_ == playerRound_;
}

void Rounds::drawRoundBoard()
{
    int unitCount = 1 + units_p->getEnemiesType().getCount();
    if (gameRound_ >= unitCount)
    {
        resetRound();
    }

    cout << "Units" << endl
         << "-----------------------------------------" << endl;

    for (int i = 0; i < unitCount; i++)
    {
        string info;

        if (i == playerRound_)
        {
            info = units_p->getPlayer().toString();
        }
        else
        {
            info = units_p->getEnemies().at(i - 1).toString();
        }

        bool isRound = i == gameRound_;
        cout << (isRound ? "-> " : "   ") << info << endl;
    }
}