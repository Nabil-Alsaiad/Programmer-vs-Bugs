#include "units.h"

Units::Units(int enemyCount)
{
    playersType_ = UnitsType("programmer", 'P', 1);
    enemiesType_ = UnitsType("bug", 'B', enemyCount);
}

void Units::fillUnits(Point boardCenter, vector<Point> randomPoints)
{
    player_ = Unit(playersType_, Stats(200, 0, 0), boardCenter, 0);
    enemies_ = vector<Unit>();

    for (int i = 0; i < randomPoints.size(); i++)
    {
        Unit unit(enemiesType_, generateRandomStats(), randomPoints[i], i);
        enemies_.push_back(unit);
    }
}

Stats Units::generateRandomStats() const
{
    int randomHealth = (rand() % 150) + 100;
    int roundedHealth = round(randomHealth / 10) * 10;

    int randomDamage = (rand() % 15) + 10;
    int randomRange = (rand() % 2) + 1;

    return Stats(roundedHealth, randomDamage, randomRange);
}

Unit Units::getPlayer() const
{
    return player_;
}

vector<Unit> Units::getEnemies() const
{
    return enemies_;
}

Unit *Units::getPlayerPointer()
{
    return &player_;
}

vector<Unit> *Units::getEnemiesPointer()
{
    return &enemies_;
}

UnitsType Units::getPlayerType() const
{
    return playersType_;
}

UnitsType Units::getEnemiesType() const
{
    return enemiesType_;
}