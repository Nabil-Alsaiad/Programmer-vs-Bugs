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

float calculateDistance(const Point &originalPosition, const Point &targetPosition)
{
    int distanceX = abs(targetPosition.x - originalPosition.x);
    int distanceY = abs(targetPosition.y - originalPosition.y);

    return (distanceX + distanceY) / 2.0f;
}
Point Units::attackClosestEnemy(Point &attackerPosition)
{
    int index = 0;

    for (int i = 1; i < enemies_.size(); i++)
    {
        if (enemies_.at(i).stats.health == 0)
        {
            continue;
        }

        float distance1 = calculateDistance(attackerPosition, enemies_.at(index).position);
        float distance2 = calculateDistance(attackerPosition, enemies_.at(i).position);

        if (distance2 < distance1)
        {
            index = i;
        }
        else if (distance2 == distance1)
        {
            int health1 = enemies_.at(index).stats.health;
            int health2 = enemies_.at(i).stats.health;

            if (health2 < health1 || (health2 == health1 && (rand() % 2) == 1))
            {
                index = i;
            }
        }
    }

    bool enemyDied = enemies_.at(index).stats.takeDamage(10);
    if (enemyDied)
    {
        return enemies_.at(index).position;
    }
    else
    {
        return Point();
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