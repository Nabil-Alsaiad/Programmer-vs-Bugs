#ifndef POD_H
#define POD_H

#pragma once

#include "units/zombie.h"

class Pod
{
private:
    int damage = 10;

    Zombie getALLZombies();
    Zombie getClosestZombie();
    Zombie getRandomZombie();
    void attackZombie();

public:
    void attackClosestZombie();
};

#endif