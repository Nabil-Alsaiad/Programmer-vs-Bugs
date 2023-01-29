#ifndef ROCK_H
#define ROCK_H

#pragma once

#include <string>

using namespace std;

class Rock
{
private:
    string hiddenObject;

public:
    string getHiddenObject();
    void chooseARandomHiddenObject();
};

#endif