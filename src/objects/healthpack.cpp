#include "healthpack.h"

#include <iostream>

using namespace std;

int HealthPack::increaseHP(int currentHP, int maxHP)
{
    return currentHP, maxHP;
}

int HealthPack::clampHP(int currentHP, int maxHP)
{
    // int currentHP;
    // const int maxHP = 100;

    int minesHP = currentHP - amountHP;
    int plsHp = currentHP + amountHP;

    // if(zombie attack alien)
    //      cout<< minsHP;
    //  else cout << plsHp;

    return currentHP;
}