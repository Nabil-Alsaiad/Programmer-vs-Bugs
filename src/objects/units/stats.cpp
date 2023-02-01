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
    string healthString = "Health: " + health_;
    string damageString = "Damage: " + damage_;

    string rangeString = "";
    if (range_ > 0)
    {
        rangeString = "Range: " + range_;
    }

    return healthString + ", " + damageString + ", " + rangeString;
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
