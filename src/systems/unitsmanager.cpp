#include <iostream>
#include <vector>
#include <string>

#include "../units/stats.cpp"
#include "../units/unit.cpp"
#include "../units/unitstype.cpp"
#include "board.h"
#include "point.h"

using namespace std;

vector<Unit> players;
vector<Unit> enemies;

UnitsType playersType("programmer", 'P', 1);
UnitsType enemiesType("bug", 'B', 2);

void fillUnitsInBoard(Board &board)
{
    Point randomPosition;

    int pCount = playersType.getCount();
    int eCount = enemiesType.getCount();

    players.clear();
    enemies.clear();

    while (pCount > 0 || eCount > 0)
    {
        randomPosition = board.getRandomPoint();
        if (!board.isInsideMap(randomPosition))
        {
            throw runtime_error("Point: " + randomPosition.toString() + " is outside of map");
        }

        if (board.isEmpty(randomPosition))
        {
            char unitSymbol;
            if (pCount > 0)
            {
                unitSymbol = playersType.getSymbol();
                int index = playersType.getCount() - pCount;

                Stats stats;
                Unit unit(playersType, stats, index);

                players.push_back(unit);
                pCount--;
            }
            else
            {
                unitSymbol = enemiesType.getSymbol();
                int index = enemiesType.getCount() - eCount;

                Stats stats;
                Unit unit(enemiesType, stats, index);

                enemies.push_back(unit);
                eCount--;
            }

            board.setObject(randomPosition, unitSymbol);
        }
    }
}

// ----------------------------------------------------------------

int gameRound = 1;

void resetRound()
{
    gameRound = 1;
}

Unit *getCurrentRoundUnit()
{
    Unit *unit;

    if (gameRound <= playersType.getCount())
    {
        unit = &(players.at(gameRound - 1));
    }
    else
    {
        unit = &(enemies.at((gameRound - 1) - playersType.getCount()));
    }

    gameRound++;

    if (gameRound >= playersType.getCount() + enemiesType.getCount())
    {
        resetRound();
    }

    return unit;
}