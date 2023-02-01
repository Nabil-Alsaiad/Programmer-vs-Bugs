#ifndef SETTINGS_H
#define SETTINGS_H

#pragma once

class Setting
{
private:
    int rowCount_, columnCount_, zombieCount_;

public:
    Setting(int row = 5, int column = 15, int zombie = 2);

    bool viewPage();

    int getRowCount() const;
    int getColumnCount() const;
    int getZombieCount() const;
};

#endif