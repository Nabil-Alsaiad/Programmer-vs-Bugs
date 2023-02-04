#include "units.h"

Units::Units(int enemyCount)
{
    playersType_ = UnitsType("programmer", 'P', 1);
    enemiesType_ = UnitsType("bug", 'B', enemyCount);

    player_ = Unit(playersType_, Stats(0, 200, 0));
    enemies_ = vector<Unit>();
}

void Units::fillUnitsInBoard(Board &board)
{
    player_.setPosition(board.getCenterPosition());
    board.setObjectAtCenter(playersType_.getSymbol());

    for (int i = 0; i < enemiesType_.getCount(); i++)
    {
        Point randomPosition = board.getRandomPoint();

        Unit unit(enemiesType_, Stats(10, 100, 2), randomPosition, i);
        board.setObject(randomPosition, enemiesType_.getSymbol());

        enemies_.push_back(unit);
    }
}

Unit Units::getPlayer() const
{
    return player_;
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