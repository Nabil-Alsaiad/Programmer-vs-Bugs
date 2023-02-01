#include <iostream>
#include "settings.h"

using namespace std;

Setting::Setting(int rows, int columns, int zombies)
{
    rowCount_ = rows;
    columnCount_ = columns;
    zombieCount_ = zombies;
}

bool Setting::viewPage()
{
    cout << "Default  settings" << endl
         << "------------------" << endl;

    cout << "Columns:  " << columnCount_ << endl;
    cout << "Rows:  " << rowCount_ << endl;
    cout << "Zombies:  " << zombieCount_ << endl;
    cout << "------------------" << endl;

    bool wantToChange = false;
    string answer = "";
    cout << "Do you want to change the settings? (y/n) => ";
    cin >> answer;

    while (true)
    {
        if (answer == "y")
        {
            wantToChange = true;
            break;
        }
        else if (answer == "n")
        {
            return true;
        }
        else
        {
            cout << "Please enter a valid character (y/n): ";
            cin >> answer;
        }
    }

    while (wantToChange)
    {
        cout << "Columns: ", cin >> columnCount_;
        int reminder = columnCount_ % 2;

        if (reminder == 1 && columnCount_ >= 9 && columnCount_ <= 17)
        {
            break;
        }

        cout << "Please enter an odd number within this range: (9 <= ? <= 17)" << endl;
    }

    while (wantToChange)
    {
        cout << "Rows: ", cin >> rowCount_;
        int reminder = rowCount_ % 2;

        if (reminder == 1 && rowCount_ >= 3 && rowCount_ <= 7)
        {
            break;
        }

        cout << "Please enter an odd number within this range: (3 <= ? <= 7)" << endl;
    }

    while (wantToChange)
    {
        cout << "Zombies: ", cin >> zombieCount_;

        if (zombieCount_ >= 1 && zombieCount_ <= 5)
        {
            break;
        }

        cout << "Zombies number must be within this range: (1 <= ? <= 5)" << endl;
    }

    return false;
}

int Setting::getRowCount() const
{
    return rowCount_;
}

int Setting::getColumnCount() const
{
    return columnCount_;
}

int Setting::getZombieCount() const
{
    return zombieCount_;
}
