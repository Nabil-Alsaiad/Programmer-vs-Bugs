#include <iostream>
#include <string>

#include "rounds.h"
#include "units.h"
#include "../units/unit.cpp"

using namespace std;

Rounds::Rounds()
{
}

void Rounds::resetRound()
{
    gameRound_ = 1;
}

bool Rounds::isPlayerRound(const Units &units)
{
    bool checkYes = gameRound_ < units.getPlayersType().getCount();
    return checkYes;
}

void Rounds::drawRoundBoard(const Units &units)
{
    int pCount = units.getPlayersType().getCount();
    int eCount = units.getEnemiesType().getCount();
    int allCount = pCount + eCount;

    // cout << "allCount: " << allCount << endl;
    // cout << "gameRound_: " << gameRound_ << endl;

    if (gameRound_ > allCount)
    {
        resetRound();
    }

    cout << "Units" << endl
         << "-----------------------------------------" << endl;

    for (int i = 0; i < allCount; i++)
    {
        // cout << "i: " << i << endl;
        string info;

        if (i < pCount)
        {
            // cout << "player index: " << i << endl;
            // cout << "Players().size(): " << units.getPlayers().size() << endl;
            // cout << "-----------------------------------------" << endl;
            info = units.getPlayers().at(i).toString();
        }
        else
        {
            // cout << "enemy index: " << i - units.getPlayersType().getCount() << endl;
            // cout << "Enemies().size(): " << units.getEnemies().size() << endl;
            // cout << "-----------------------------------------" << endl;
            info = units.getEnemies().at(i - units.getPlayersType().getCount()).toString();
        }

        bool isRound = i == gameRound_ - 1;
        cout << (isRound ? "-> " : "   ") << info << endl;
    }

    gameRound_++;
}