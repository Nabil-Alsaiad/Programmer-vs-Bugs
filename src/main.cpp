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
#include "units/unit.cpp"
#include "units/unitstype.cpp"
#include "user/settings.cpp"
#include "user/commands.cpp"

using namespace std;
using namespace pf;

void settingsMenu(Setting &settings)
{
     while (true)
     {
          ClearScreen();
          if (settings.viewPage())
          {
               break;
          }
     }
}

void gameMenu(Board &board, Rounds &rounds, Units &units)
{
     bool playerDied;

     while (true)
     {
          if (rounds.shouldResetRound(units))
          {
               // ClearScreen();
               cout << "\nNEW SCREEN ================================\n\n";

               board.display();
               rounds.drawUnitsBoard(units, false);
               board.spawnFeatures(units.getEnemiesPointer());

               Pause();
               board.clearTrials();
          }

          // ClearScreen();
          cout << "\nNEW SCREEN ================================\n\n";

          board.display();
          rounds.drawUnitsBoard(units);

          if (playerDied)
          {
               cout << "\nGAME OVER" << endl
                    << "Programmer has lost his mind while trying to fix the bugs." << endl
                    << "Taking a break and planning the code is much better than trial and error, also don't relay on AI or copy pasting and focus on improving your programming basics" << endl;
               break;
          }

          bool roundEnded = true;

          if (rounds.isPlayerRound())
          {
               roundEnded = checkInput(board, units);
          }
          else
          {
               playerDied = rounds.playEnemyRound(board, units);
               Pause();
          }

          if (roundEnded)
          {
               rounds.increaseRound();
          }
     }
}

int main()
{
     srand(time(NULL));

     Setting settings;
     settingsMenu(settings);

     Units units(settings.getBugCount());
     Board board(settings.getDimensions());
     Rounds rounds;

     board.fillUnits(units);
     gameMenu(board, rounds, units);

     return 0;
}
