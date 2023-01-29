#include "rock.h"

#include <iostream>

using namespace std;

string Rock::getHiddenObject()
{
    return hiddenObject;
}

void Rock::chooseARandomHiddenObject()
{
    string otherObject[] = {"h", "p", "<", ">", "^", "bottom", " "}; // i dont have bottom one
    int otherNumber = 7;
    for (int i = 0; i < otherNumber; i++)
    {
        int randomOther = rand() % otherNumber;

        string r = otherObject[randomOther];
    }
}
