#include <iostream>
#include <string>
#include "../systems/point.h"
#include "../systems/board.h"
#include "../systems/units.h"
#include "../systems/movement.cpp"

using namespace std;

char convertDirectionToArrow(string directionInput)
{
    bool isUp = directionInput == "u" || directionInput == "up";
    bool isDown = directionInput == "d" || directionInput == "down";
    bool isRight = directionInput == "r" || directionInput == "right";
    bool isLeft = directionInput == "l" || directionInput == "left";

    return isUp      ? '^'
           : isDown  ? 'v'
           : isRight ? '>'
           : isLeft  ? '<'
                     : ' ';
}

void printCommands()
{
    cout << "Help commands:" << endl
         << "- h/help -> Display user commands" << endl
         << "- m/move -> Move the programmer" << endl
         << "- a/arrow -> Change an arrow direction" << endl
         //  << "- s/save -> Save the game" << endl
         //  << "- ld/load -> Load the game" << endl
         << "- q/quit -> Quit the game" << endl;
}

void checkMoveCommand(Board &board, Units &units)
{
    string input;

    while (true)
    {
        cout << "Provide movement direction: (u/up | d/down | r/right | l/left)> ", cin >> input;

        bool isUp = input == "u" || input == "up";
        bool isDown = input == "d" || input == "down";
        bool isRight = input == "r" || input == "right";
        bool isLeft = input == "l" || input == "left";

        if (isUp || isDown || isRight || isLeft)
        {
            break;
        }

        cout << "Wrong input!" << endl;
    }

    char arrow = convertDirectionToArrow(input);
    movePlayer(board, units, arrow);
}

void checkArrowCommand(Board &board)
{
    int x, y;
    string dir;

    cout << "Provide arrow location and new direction: x y (u|d|r|l)> ", cin >> x >> y >> dir;

    Point pos(x, y);
    char obj = board.getObject(pos);

    // if (obj != ">" && obj != "<" && obj != "^" && obj != "v")
    // {
    //     cout << "Wrong location! choose again";
    // }

    board.setObject(pos, convertDirectionToArrow(dir));
}

bool checkInput(Board &board, Units &units)
{
    string input;

    while (true)
    {
        cout << "\nWrite your command> ", cin >> input;

        if (input == "h" || input == "help")
        {
            printCommands();
        }
        else if (input == "m" || input == "move")
        {
            checkMoveCommand(board, units);
            return true;
        }
        else if (input == "a" || input == "arrow")
        {
            checkArrowCommand(board);
            return false;
        }
        else if (input == "q" || input == "quit")
        {
            exit(0);
        }
        else
        {
            cout << "Unknown command, type 'h' or 'help' for list of all commands" << endl;
        }
    }

    return false;
}