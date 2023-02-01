#include <iostream>

#include <string>

int main()
{

    std::string input;
    // declares a string variable called "input"

    std::cout << "Enter command: ";
    // outputs the prompt "Enter command:" to the console

    std::cin >> input;
    // takes user input and stores it in the "input" variable

    if (input == "h")
    {
        // checks if the "input" is equal to "h"

        std::cout << "Help commands:\n"
                  << "1. u - Move up.\n"
                  << "2. d - Move down.\n"
                  << "4. l - Move left.\n"
                  << "5. r - Move right.\n"
                  << "6. arrow - Change the direction of an arrow.\n"
                  << "7. h - Display these user commands.\n"
                  << "8. save - Save the game.\n"
                  << "9. load - Load the game.\n"
                  << "10. quit - Quit the game.\n";
    }
    else
    {
        std::cout << "Unknown command. Type 'h' for list of commands.\n";

        return 0;
    }
