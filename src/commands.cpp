#include <iostream>
#include <string>

using namespace std;

int checkInput()
{
    string input;

    cout << "Enter command: ";
    cin >> input;

    if (input == "h")
    {
        cout << "Help commands:\n"
             << "1. u - Move up.\n"
             << "2. d - Move down.\n"
             << "4. l - Move left.\n"
             << "5. r - Move right.\n"
             //  << "6. arrow - Change the direction of an arrow.\n"
             << "7. h - Display user commands.\n"
             //  << "8. save - Save the game.\n"
             //  << "9. load - Load the game.\n"
             << "10. quit - Quit the game.\n";
    }
    else
    {
        cout << "Unknown command. Type 'h' for list of commands.\n";
    }

    cout << "Enter a direction (u, d, r, l) =>";
    cin >> input;

    if (input == "u" || input == "d" || input == "l" || input == "r")
    {
        cout << "You entered " << input << "." << endl;
    }
    else
    {
        cout << "Error: Input must be 'u', 'd', 'l', or 'r'." << endl;
    }
}