#ifndef POD_H
#define POD_H

#include "zombie.h"
#pragma once

class Pod
{
public:
    void attackclosestzombie();

private:
    zombie getALLZombies();
    zombie getclosestZomcie();
    zombie getrandomZombie();
    void attackZoombie();

private:
    int damage = 10;


};

#endif