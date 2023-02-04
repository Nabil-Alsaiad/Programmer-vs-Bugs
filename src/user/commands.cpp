#include <iostream>
#include <string>
#include "../systems/point.h"
#include "../systems/board.h"

using namespace std;

char convertDirectionToArrow(char dir)
{
    return dir == 'u'   ? '^'
           : dir == 'd' ? 'v'
           : dir == 'r' ? '>'
                        : '<';
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

void checkMoveCommand()
{
    string input;

    cout << "Provide movement direction> (u|d|r|l)" << endl;
    cin >> input;

    if (input == "u" || input == "up")
    {
    }
    else if (input == "d" || input == "down")
    {
    }
    else if (input == "r" || input == "right")
    {
    }
    else if (input == "l" || input == "left")
    {
    }
}

void checkArrowCommand(Board &board)
{
    int x, y;
    char dir;

    cout << "Provide arrow location and new direction> x y (u|d|r|l)" << endl;
    cin >> x >> y >> dir;

    Point pos(x, y);
    char obj = board.getObject(pos);

    // if (obj != '>' && obj != '<' && obj != '^' && obj != 'v')
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
            checkMoveCommand();
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