#ifndef SETTINGS_H
#define SETTINGS_H

#pragma once

#include <iostream>
#include "../systems/point.h"

using namespace std;

class Setting
{
private:
    int rowCount_, columnCount_, bugCount_;

public:
    Setting(int row = 5, int column = 15, int zombie = 2);

    bool viewPage();

    Point getDimensions() const;
    int getBugCount() const;
};

#endif