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
    gameRound_ = 0;
}

bool Rounds::isPlayerRound()
{
    bool checkYes = gameRound_ <= units_p->getPlayerType().getCount();
    return checkYes;
}

void Rounds::drawRoundBoard()
{
    int eCount = units_p->getEnemiesType().getCount();
    int allCount = 1 + eCount;

    if (gameRound_ >= allCount)
    {
        resetRound();
    }

    cout << "Units" << endl
         << "-----------------------------------------" << endl;

    for (int i = 0; i < allCount; i++)
    {
        string info;

        if (i == 0)
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