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
    return gameRound_ <= units.getPlayersType().getCount();
}

void Rounds::drawRoundBoard(const Units &units)
{
    int allCount = units.getPlayersType().getCount();
    +units.getEnemiesType().getCount();

    if (gameRound_ >= allCount)
    {
        resetRound();
    }

    cout << "allCount: " << allCount << endl;

    for (int i = 0; i < allCount; i++)
    {
        string info;

        if (isPlayerRound(units))
        {
            cout << "gameRound_ - 1: " << gameRound_ - 1 << endl;
            info = units.getPlayers().at(gameRound_ - 1).toString();
        }
        else
        {
            cout << "gameRound_ - units.getPlayersType().getCount() - 1: " << gameRound_ - units.getPlayersType().getCount() - 1 << endl;
            info = units.getEnemies().at(gameRound_ - units.getPlayersType().getCount() - 1).toString();
        }

        cout << "info: " << info << endl;
        cout << "gameRound: " << gameRound_ << endl;
        cout << "i: " << i << endl;

        bool isRound = i == gameRound_ - 1;
        cout << (isRound ? "-> " : "   ") << info << endl;
    }

    gameRound_++;
}