#ifndef STATS_H
#define STATS_H

#pragma once

#include <string>

using namespace std;

struct Stats
{
public:
    int health, maxHealth;
    int damage;
    int range;

    Stats(int maxHealth = 100, int damage = 10, int range = 0);

    string toString() const;

    bool takeDamage(int damage);
    void heal(int amount);
};

#endif