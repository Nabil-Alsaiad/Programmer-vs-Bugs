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
#include "systems/rover.cpp"
#include "systems/point.cpp"
#include "systems/unitsmanager.cpp"

using namespace std;
using namespace pf;

string names = "[Nabil Alsaiad, Hilmi Zaki, Asem Maroof]";

int main()
{
     srand(time(NULL));

     cout << "Assignment (Part 1) by " + names << endl;

     Board board;
     fillUnitsInBoard(board);

     while (true)
     {
          ClearScreen();
          board.display();
          Pause();
     }
}