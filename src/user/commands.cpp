#include <iostream>
#include <string>
#include "../systems/point.h"

using namespace std;

// void checkInput(Board &board)
bool checkInput()
{
    string input;

    cout << endl
         << endl
         << "Write your command> ";
    cin >> input;

    if (input == "h" || input == "help")
    {
        cout << "Help commands:\n"
             << "- h/help -> Display user commands.\n"
             //  << "- u/up -> Move up.\n"
             //  << "- d/down -> Move down.\n"
             //  << "- l/left -> Move left.\n"
             //  << "- r/right -> Move right.\n"
             << "- a/arrow -> Change the direction of an arrow.\n"
             //  << "- s/save -> Save the game.\n"
             //  << "- ld/load -> Load the game.\n"
             << "- q/quit -> Quit the game.\n";

        return false;
    }
    // else if (input == "u" || input == "up")
    // {
    // }
    // else if (input == "d" || input == "down")
    // {
    // }
    // else if (input == "r" || input == "right")
    // {
    // }
    // else if (input == "l" || input == "left")
    // {
    // }
    // else if (input == "a" || input == "arrow")
    // {
    //     int x, y;
    //     char dir;

    //     cout << "Provide arrow location and new direction> x y (u|d|r|l)" << endl;
    //     cin >> x >> y >> dir;

    //     cout << "x: " << x << endl
    //          << "y: " << y << endl
    //          << "dir: " << dir << endl;

    //     Point pos(x, y);
    //     char obj = board.getObject(pos);
    //     // if (obj != '>' && obj != '<' && obj != '^' && obj != 'v')
    //     // {
    //     //     cout << "Wrong location! choose again";
    //     //     cin >> x >> y >> dir;
    //     // }
    //     // else
    //     // {
    //     char newArrow = dir == 'u'   ? '^'
    //                     : dir == 'd' ? 'v'
    //                     : dir == 'r' ? '>'
    //                                  : '<';
    //     board.setObject(pos, newArrow);
    //     // }
    // }
    else if (input == "q" || input == "quit")
    {
        exit(0);
    }
    else
    {
        cout << "Unknown command. Type 'h' for list of commands.\n";
    }
}