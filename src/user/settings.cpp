#include "settings.h"

Setting::Setting(int rowCount, int columnCount, int bugCount)
{
    rowCount_ = rowCount;
    columnCount_ = columnCount;
    bugCount_ = bugCount;
}

bool Setting::viewPage()
{
    cout << " Made by:\n - Nabil Alsaiad\n - Asem Maroof\n - Hilmi Zaki\n";

    cout
        << "\n Default  settings"
        << "\n ----------------------";

    cout << "\n Columns:  " << columnCount_
         << "\n Rows:  " << rowCount_
         << "\n Bugs:  " << bugCount_;

    string answer = "";
    cout << "\n\n Do you want to change the settings? (y/n) => ", cin >> answer;

    bool wantToChange = false;
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
            cout << "Please enter a valid character (y/n): ", cin >> answer;
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

        cout << "Please enter an odd number within this range: (9 <= ? <= 17)\n";
    }

    while (wantToChange)
    {
        cout << "Rows: ", cin >> rowCount_;
        int reminder = rowCount_ % 2;

        if (reminder == 1 && rowCount_ >= 3 && rowCount_ <= 7)
        {
            break;
        }

        cout << "Please enter an odd number within this range: (3 <= ? <= 7)\n";
    }

    while (wantToChange)
    {
        cout << "Bugs: ", cin >> bugCount_;

        if (bugCount_ >= 1 && bugCount_ <= 5)
        {
            break;
        }

        cout << "Bugs number must be within this range: (1 <= ? <= 5)\n";
    }

    return false;
}

Point Setting::getDimensions() const
{
    return Point(columnCount_, rowCount_);
}

int Setting::getBugCount() const
{
    return bugCount_;
}
