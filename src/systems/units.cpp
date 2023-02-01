#include "units.h"

Units::Units()
{
    playersType_ = UnitsType("programmer", 'P', 1);
    enemiesType_ = UnitsType("bug", 'B', 2);

    players_ = vector<Unit>();
    enemies_ = vector<Unit>();
}

void Units::fillUnitsInBoard(Board &board)
{
    Point randomPosition;

    int pCount = playersType_.getCount();
    int eCount = enemiesType_.getCount();

    players_.clear();
    enemies_.clear();

    cout << "Players: " << players_.size() << endl;
    cout << "Enemies: " << enemies_.size() << endl;

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
                unitSymbol = playersType_.getSymbol();
                int index = playersType_.getCount() - pCount;

                Stats stats(100, 100, 100);
                Unit unit(playersType_, stats, index);

                players_.push_back(unit);
                pCount--;
            }
            else
            {
                unitSymbol = enemiesType_.getSymbol();
                int index = enemiesType_.getCount() - eCount;

                Stats stats(100, 100, 100);
                Unit unit(enemiesType_, stats, index);

                enemies_.push_back(unit);
                eCount--;
            }

            board.setObject(randomPosition, unitSymbol);
        }
    }

    cout << "player vector length" << players_.size() << endl;
    cout << "enemy vector length" << enemies_.size() << endl;
}

vector<Unit> Units::getPlayers() const
{
    return vector<Unit>();
}

vector<Unit> Units::getEnemies() const
{
    return vector<Unit>();
}

UnitsType Units::getPlayersType() const
{
    return playersType_;
}
UnitsType Units::getEnemiesType() const
{
    return enemiesType_;
}