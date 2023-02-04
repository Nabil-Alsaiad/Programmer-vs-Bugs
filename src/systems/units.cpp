#include <cmath>
#include "units.h"
using namespace std;

Units::Units(int enemyCount)
{
    playersType_ = UnitsType("programmer", 'P', 1);
    enemiesType_ = UnitsType("bug", 'B', enemyCount);

    player_ = Unit(playersType_, Stats(200, 0, 0));
    enemies_ = vector<Unit>();
}

void Units::fillUnits(Point boardCenter, vector<Point> randomPoints)
{
    player_.setPosition(boardCenter);

    for (int i = 0; i < randomPoints.size(); i++)
    {
        Unit unit(enemiesType_, Stats(getRandomHealth(), 10, rand() % 3), randomPoints[i], i);
        enemies_.push_back(unit);
    }
}

int Units::getRandomHealth()
{
    int randomNumber = round((rand() % 150) / 10) * 10;
    return randomNumber + 100;
}

Unit Units::getPlayer() const
{
    return player_;
}

vector<Unit> Units::getEnemies() const
{
    return enemies_;
}

UnitsType Units::getPlayerType() const
{
    return playersType_;
}

UnitsType Units::getEnemiesType() const
{
    return enemiesType_;
}