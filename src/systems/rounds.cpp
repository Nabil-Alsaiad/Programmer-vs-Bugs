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
}

Rounds::Rounds(Units *units)
{
    units_p = units;
}

void Rounds::increaseRound()
{
    gameRound_++;
}

void Rounds::resetRound()
{
    gameRound_ = 1;
}

bool Rounds::isPlayerRound()
{
    bool checkYes = gameRound_ <= units_p->getPlayersType().getCount();
    return checkYes;
}

void Rounds::drawRoundBoard()
{
    int pCount = units_p->getPlayersType().getCount();
    int eCount = units_p->getEnemiesType().getCount();
    int allCount = pCount + eCount;

    if (gameRound_ > allCount)
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
            int index = i - units_p->getPlayersType().getCount();
            info = units_p->getEnemies().at(index).toString();
        }

        bool isRound = i == gameRound_ - 1;
        cout << (isRound ? "-> " : "   ") << info << endl;
    }
}