// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: T14L
// Names: Nabil | Hilmi | Asem
// IDs: 1221301330 | 1221301686 | 1211306893
// Emails: 1221301330@student.mmu.edu.my | 1221301686@student.mmu.edu.my | 1211306893@student.mmu.edu.my
// Phones: +60 11-1174 1088 | +60 17-295 2865 | +60 17‑631 7864
// *********************************************************

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "pf/helper.cpp"
#include "systems/board.cpp"
#include "systems/point.cpp"
#include "systems/units.cpp"
#include "systems/rounds.cpp"
#include "units/stats.cpp"
#include "user/settings.cpp"
#include "user/commands.cpp"

using namespace std;
using namespace pf;

int main()
{
     srand(time(NULL));

     Setting settings;

     while (true)
     {
          ClearScreen();
          if (settings.viewPage())
          {
               break;
          }
     }

     Point dimensions(settings.getColumnCount(), settings.getRowCount());
     Board board(dimensions);
     Units units(1, settings.getZombieCount());
     Rounds rounds;

     units.fillUnitsInBoard(board);

     while (true)
     {
          ClearScreen();

          board.display();
          rounds.drawRoundBoard(units);
          // rounds.playRound(units);

          if (rounds.isPlayerRound(units))
          {
               checkInput(board);
          }
          else
          {
               Pause();
          }

          rounds.increaseRound();
     }

     return 0;
}
