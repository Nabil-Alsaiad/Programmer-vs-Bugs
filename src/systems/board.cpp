#include "board.h"
#include "point.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()

using namespace std;

Board::Board(int dimX, int dimY)
{
    init(dimX, dimY);
}

void Board::init(int dimX, int dimY)
{
    dimX_ = dimX;
    dimY_ = dimY;
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ',
                      'h', 'r', 'p', '#', '@', '$'};
    int numberOfObjects = 12;

    // create dynamic 2D array using vector
    map_.resize(dimY_); // create empty rows
    for (int i = 0; i < dimY_; ++i)
    {
        map_[i].resize(dimX_); // resize each row
    }

    // put random characters into the vector array
    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
            int objNo = rand() % numberOfObjects;
            map_[i][j] = objects[objNo];
        }
    }
}

int Board::getDimX() const
{
    return dimX_;
}

int Board::getDimY() const
{
    return dimY_;
}

char Board::getObject(Point position) const
{
    return map_[dimY_ - position.y][position.x - 1];
}
void Board::setObject(Point position, char ch)
{
    map_[dimY_ - position.y][position.x - 1] = ch;
}

bool Board::isEmpty(Point position) const
{
    return map_[dimY_ - position.y][position.x - 1] == ' ';
}
bool Board::isInsideMap(Point position) const
{
    return (position.x > 0 && position.x <= dimX_) && (position.y > 0 && position.y <= dimY_);
}

Point Board::getRandomPoint() const
{
    int randomX = rand() % dimX_ + 1;
    int randomY = rand() % dimY_ + 1;

    return Point(randomX, randomY);
}

void Board::display() const
{
#pragma region each row
    for (int i = 0; i < dimY_; ++i)
    {
        // display upper border of the row
        cout << " ";
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;

        // display row number
        cout << setw(2) << (dimY_ - i);

        // display cell content and border of each column
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }
#pragma endregion

#pragma region lower border of the last row
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
#pragma endregion

#pragma region column number
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";

        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
#pragma endregion
}