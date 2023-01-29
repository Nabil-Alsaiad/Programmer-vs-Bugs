// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: T14L
// Names: Nabil | Hilmi | Asem
// IDs: 1221301330 | 1221301686 | 1211306893
// Emails: 1221301330@student.mmu.edu.my | 1221301686@student.mmu.edu.my | 1211306893@student.mmu.edu.my
// Phones: +60 11-1174 1088 | +60 17-295 2865 | +60 17‑631 7864
// *********************************************************

#include "pf/helper.cpp"
#include "systems/board.cpp"
#include "systems/rover.cpp"
#include "systems/point.cpp"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()

using namespace std;

string names = "[Nabil Alsaiad, Hilmi Zaki, Asem Maroof]";

int main()
{
     // srand(1); // fixed map
     srand(time(NULL)); // random map

     cout << "Assignment (Part 1) by " + names << endl
          << "Let's Get Started!" << endl;

     Board board;
     Point randomPosition;

     int playerNumber = 1, enemyNumber = 2;
     while (playerNumber > 0 || enemyNumber > 0)
     {
          randomPosition = board.getRandomPoint();
          if (!board.isInsideMap(randomPosition))
          {
               throw std::runtime_error("Point: " + randomPosition.toString() + " is outside of map");
          }

          if (board.isEmpty(randomPosition))
          {
               char unit;
               if (playerNumber > 0)
               {
                    unit = 'A';
                    playerNumber--;
               }
               else
               {
                    unit = 'Z';
                    enemyNumber--;
               }
               board.setObject(randomPosition, unit);
          }
     }

     while (true)
     {
          pf::ClearScreen();
          board.display();
          pf::Pause();
     }
}
