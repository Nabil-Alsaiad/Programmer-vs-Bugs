//TOADD;
// clear the page after put a new sitting 

#include <iostream>
using namespace std;


class Setting{
    private: int rowCount, columnCount, zombieCount;

    public: 
    Setting(int row = 5, int column = 9, int zombie = 1);
    void viewPage();


};

Setting::Setting(int  row, int column, int zombie){
    rowCount = row;
    columnCount = column;
    zombieCount = zombie;
}

void Setting::viewPage(){
    cout << "Default  settings" << endl << endl;
    cout << "------------------" << endl;
    cout << "Column:  " << columnCount << endl;
    cout << "Rows:  " << rowCount << endl;
    cout << "Zombie:  " << zombieCount << endl;
    cout << "------------------" << endl;

    bool wantToChange = false;
    string answers = "";
    cout << "Do you want to change the settings? (y/n) => ";
    cin >> answers; cout << endl;


    while(true){
        if(answers == "y"){
        wantToChange = true;
        break;
        }

        else if(answers == "n"){
        wantToChange;
        break;
        }
        
        
        else 
        {
        cout<< "please enter a valued char (y/n): ";
        cin >> answers; cout << endl;
        
        }

        
    }

    while(wantToChange)
    {
        cout << "Rows:", cin >> rowCount;
        int reminder = rowCount % 2;

        cout << "Reminder: " << reminder << endl;

        if(reminder == 1 && rowCount > 2 && rowCount < 9){
            break;
        }
        
        cout << "please enter an odd number."<< endl
            << "note: maximum number is 9"<< endl
            << "note: minimum nomber is 3"<< endl;
    }

    while(wantToChange){
        cout << "columns:", cin >> columnCount;
        int reminder = columnCount % 2;

        if(reminder == 1 && columnCount >= 9 && columnCount <= 16){
            break;
        }

        cout << "please enter an odd number."<< endl
            << "note: maximum number is 16"<< endl
            << "note: minimum nomber is 9" << endl;
        
    }

    while(wantToChange){
        cout << "zombie:", cin >> zombieCount;

        if(zombieCount > 1 && zombieCount <5){
            break;
        }

        cout << "zombies min is 1" << endl
             << "zombies max is 5" <<endl;
    }
}