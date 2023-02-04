#include <iostream>
#include <string>
#include "../systems/point.h"
#include "../systems/board.h"

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

void checkMoveCommand(Board &board)
{
    string input;

    while (true)
    {
        cout << "Provide movement direction> (u/up | d/down | r/right | l/left)" << endl;
        cin >> input;

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
    board.movePlayer(arrow);
}

void checkArrowCommand(Board &board)
{
    int x, y;
    string dir;

    cout << "Provide arrow location and new direction> x y (u|d|r|l)" << endl;
    cin >> x >> y >> dir;

    Point pos(x, y);
    char obj = board.getObject(pos);

    // if (obj != ">" && obj != "<" && obj != "^" && obj != "v")
    // {
    //     cout << "Wrong location! choose again";
    // }

    board.setObject(pos, convertDirectionToArrow(dir));
}

void checkInput(Board &board)
{
    string input;

    while (true)
    {
        cout << "\nWrite your command> ";
        cin >> input;

        if (input == "h" || input == "help")
        {
            printCommands();
        }
        else if (input == "m" || input == "move")
        {
            checkMoveCommand(board);
            break;
        }
        if (input == "a" || input == "arrow")
        {
            checkArrowCommand(board);
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
}