#include "Rock.h"
#include <iostream>

using namespace std;

Rock::Rock()
{

}

string Rock::gethiddenObject(){
    return hiddenObject;
}

void Rock::chooseARandomHiddenObject(){
    string otherObject[] = {"h" , "p" , "<" , ">", "^", "bottom", " "}; //i dont have bottom one 
    int numberother = 7;
    for(int i =0; i < numberother; i++){
        int randomOther = random() % numberother;

        string r = otherObject[randomOther];
    }
}

