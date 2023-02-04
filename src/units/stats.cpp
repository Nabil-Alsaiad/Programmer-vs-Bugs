#include <string>
#include "stats.h"

using namespace std;

Stats::Stats(int maxHealth, int damage, int range)
{
    maxHealth_ = maxHealth;
    health_ = maxHealth;
    damage_ = damage;
    range_ = range;
}

string Stats::toString() const
{
    string healthString = "Health: " + to_string(health_);
    string damageString = "Damage: " + to_string(damage_);

    string rangeString = "";
    if (range_ > 0)
    {
        rangeString = ", Range: " + to_string(range_);
    }

    return healthString + ", " + damageString + rangeString;
}

bool Stats::takeDamage(int damage)
{
    health_ -= damage;
    if (health_ < 0)
    {
        health_ = 0;
    }

    if (health_ == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Stats::heal(int amount)
{
    health_ += amount;
    if (health_ > maxHealth_)
    {
        health_ = maxHealth_;
    }
}

void Stats::increaseDamage(int amount)
{
    damage_ += amount;
}

void Stats::resetDamage()
{
    damage_ = 0;
}