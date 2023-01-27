#ifndef HEALTHPACK_H
#define HEALTHPACK_H

#pragma once

class healthPack
{
public:
    int increaseHP(int currentHP, int maxHP);

private:
    int clampHP (int currentHP, int maxHP);

private:
    int amountHP = 20;
};

#endif