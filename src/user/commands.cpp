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
    cout << "Help commands:\n"
         << "- h/help -> Display user commands\n"
         << "- m/move -> Move the programmer\n"
         << "- a/arrow -> Change an arrow direction\n"
         //  << "- s/save -> Save the game\n"
         //  << "- ld/load -> Load the game\n"
         << "- q/quit -> Quit the game\n";
}

void checkMoveCommand(Board &board, Units &units)
{
    string input;
    char arrow;
    bool isInputWrong;

    do
    {
        cout << "Provide movement direction: (u/up | d/down | r/right | l/left) => ";
        cin >> input;

        arrow = convertDirectionToArrow(input);
        isInputWrong = arrow == ' ';

        if (isInputWrong)
        {
            cout << "Wrong input!\n";
        }
    } while (isInputWrong);

    movePlayer(board, units, arrow);
}

void checkArrowCommand(Board &board)
{
    int x, y;
    string dir;
    Point pos;

    while (true)
    {
        cout << "Provide arrow location and new direction: x y (u|d|r|l) => ", cin >> x >> y >> dir;

        pos = Point(x, y);
        char obj = board.getObject(pos);

        if (obj != '>' && obj != '<' && obj != '^' && obj != 'v')
        {
            cout << "Wrong location! choose again";
        }
        else
        {
            break;
        }
    }

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
            cout << "Unknown command, type 'h' or 'help' for list of all commands\n";
        }
    }

    return false;
}