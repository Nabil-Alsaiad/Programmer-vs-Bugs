#ifndef STATS_H
#define STATS_H

#pragma once

#include <string>

using namespace std;

class Stats
{
private:
    int health_, maxHealth_;
    int damage_;
    int range_;

public:
    Stats(int maxHealth = 100, int damage = 10, int range = 0);

    string toString() const;

    bool takeDamage(int damage);
    void heal(int amount);

    void increaseDamage(int amount);
    void resetDamage();

#endif