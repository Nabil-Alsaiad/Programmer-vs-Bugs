#include "stats.h"

Stats::Stats(int maxHealth, int damage, int range)
{
    this->maxHealth = maxHealth;
    this->health = maxHealth;
    this->damage = damage;
    this->range = range;
}

string Stats::toString() const
{
    string healthString = "Health: " + to_string(health);
    string damageString = ", Damage: " + to_string(damage);

    string rangeString = "";
    if (range > 0)
    {
        rangeString = ", Range: " + to_string(range);
    }

    return healthString + damageString + rangeString;
}

bool Stats::takeDamage(int damage)
{
    health -= damage;
    if (health < 0)
    {
        health = 0;
    }

    if (health == 0)
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
    health += amount;
    if (health > maxHealth)
    {
        health = maxHealth;
    }
}