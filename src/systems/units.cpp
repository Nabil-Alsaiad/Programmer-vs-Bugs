#include "units.h"

Units::Units(int playerCount, int enemyCount)
{
    playersType_ = UnitsType("programmer", 'P', playerCount);
    enemiesType_ = UnitsType("bug", 'B', enemyCount);

    players_ = vector<Unit>();
    enemies_ = vector<Unit>();
}

void Units::fillUnitsInBoard(Board &board)
{
    Point randomPosition;
    bool first = true;

    int pCount = playersType_.getCount();
    int eCount = enemiesType_.getCount();

    while (pCount > 0 || eCount > 0)
    {
        randomPosition = board.getRandomPoint();

        if (board.isEmpty(randomPosition))
        {
            char unitSymbol;
            if (pCount > 0)
            {
                unitSymbol = playersType_.getSymbol();
                int index = playersType_.getCount() - pCount;

                Stats stats(0, 200, 0);
                Unit unit(playersType_, stats, index);

                players_.push_back(unit);
                pCount--;
            }
            else
            {
                unitSymbol = enemiesType_.getSymbol();
                int index = enemiesType_.getCount() - eCount;

                Stats stats(10, 100, 2);
                Unit unit(enemiesType_, stats, index);

                enemies_.push_back(unit);
                eCount--;
            }

            if (first)
            {
                first = false;
                board.setObjectAtCenter(unitSymbol);
            }
            else
            {
                board.setObject(randomPosition, unitSymbol);
            }
        }
    }
}

vector<Unit> Units::getPlayers() const
{
    return players_;
}

vector<Unit> Units::getEnemies() const
{
    return enemies_;
}

UnitsType Units::getPlayersType() const
{
    return playersType_;
}
UnitsType Units::getEnemiesType() const
{
    return enemiesType_;
}