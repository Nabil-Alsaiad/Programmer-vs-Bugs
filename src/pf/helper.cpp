#include "helper.h"
#include <cstdlib>
#include <iostream>

namespace pf
{
    const int yMax = 3;
    const int xMax = 5;
    char kBoard[yMax][xMax];

    int ClearScreen()
    {
#if defined(_WIN32)
        return std::system("cls");
#elif defined(__linux__) || defined(__APPLE__)
        return std::system("clear");
#endif
    }

    int Pause()
    {
#if defined(_WIN32)
        return std::system("pause");
#elif defined(__linux__) || defined(__APPLE__)
        return std::system(R"(read -p "Press any key to continue . . . " dummy)");
#endif
    }

    void CreateGameBoard()
    {
        for (int y = 0; y < yMax; ++y)
            for (int x = 0; x < xMax; ++x)
            {
                int random_number = std::rand() % 2;
                if (random_number)
                    kBoard[y][x] = '*';
                else
                    kBoard[y][x] = 'r';
            }
    }

    void ShowGameBoard()
    {
        for (int y = 0; y < yMax; ++y)
        {
            for (int x = 0; x < xMax; ++x)
            {
                std::cout << kBoard[y][x];
            }
            std::cout << std::endl;
        }
    }
}