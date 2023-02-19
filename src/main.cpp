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

bool endGame(bool hasWon)
{
     if (hasWon)
     {
          cout << "\n========\nGAME WON\n========\n"
               << "\nProgrammer has successfully fixed all the bugs, the time and effort spent in watching tutorials, reading documentations and solving problems has paid off.Don't underestimate the learning journey and don't look at it's length and difficulty, because it's what will make you able to fix those silly bugs that pop up everywhere all the time.\n\n";
     }
     else
     {
          cout << "\n=========\nGAME OVER\n=========\n"
               << "\nProgrammer has lost his mind while trying to fix the bugs.\nTaking a break and planning the code is much better than trial and error, also don't relay on AI or copy pasting and focus on improving your programming basics.\n\n";
     }

     do
     {
          cout << "Do you want to play again? (y/n) => ";

          char answer;
          cin >> answer;

          if (answer == 'y')
          {
               return true;
          }
          else if (answer == 'n')
          {
               return false;
          }
          else
          {
               cout << "Wrong input!!\n";
          }

     } while (true);
}

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

bool gameMenu(Board &board, Rounds &rounds, Units &units)
{
     bool playerDied;

     while (true)
     {
          if (rounds.shouldResetRound(units))
          {
               // ClearScreen();
               cout << "\nNEW SCREEN ================================\n\n";

               bool allEnemiesAreDead = board.spawnFeatures(units.getEnemiesPointer());
               if (allEnemiesAreDead)
               {
                    return endGame(true);
               }
               else
               {
                    board.display();
                    rounds.drawUnitsBoard(units, false);
                    Pause();
                    board.clearTrials();
               }
          }

          // ClearScreen();
          cout << "\nNEW SCREEN ================================\n\n";

          if (playerDied)
          {
               return endGame(false);
          }

          board.display();
          rounds.drawUnitsBoard(units);

          bool roundEnded = true;

          if (rounds.isPlayerRound())
          {
               roundEnded = checkInput(board, units);
          }
          else
          {
               vector<Unit> *enemies_p = units.getEnemiesPointer();
               Unit *enemy_p = &(enemies_p->at(rounds.getEnemyRoundIndex()));

               if (enemy_p->stats.health > 0)
               {
                    playerDied = rounds.playEnemyRound(board, units.getPlayerPointer(), enemy_p);
                    Pause();
               }
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

     while (true)
     {
          settingsMenu(settings);

          Units units(settings.getBugCount());
          Board board(settings.getDimensions());
          Rounds rounds;

          board.fillUnits(units);
          bool restart = gameMenu(board, rounds, units);

          if (!restart)
          {
               break;
          }
     }

     return 0;
}
