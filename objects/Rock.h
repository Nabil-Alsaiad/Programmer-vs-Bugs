#ifndef ROCK_H
#define ROCK_H

#include <string>

using namespace std;
#pragma once

class Rock
{
public:
    string gethiddenObject();
    void chooseARandomHiddenObject();


private:
    string hiddenObject;
};

#endif