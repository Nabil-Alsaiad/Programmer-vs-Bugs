#ifndef HEALTH_PACK_H
#define HEALTH_PACK_H

#pragma once

class HealthPack
{
private:
    int amountHP = 20;

    int clampHP(int currentHP, int maxHP);

public:
    int increaseHP(int currentHP, int maxHP);
};

#endif