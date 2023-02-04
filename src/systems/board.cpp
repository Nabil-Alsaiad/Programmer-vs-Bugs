#include "board.h"
#include "point.h"
#include <iostream>
#include <iomanip>

using namespace std;

Board::Board(Point dim)
{
    init(dim);
}

void Board::init(const Point &dim)
{
    dim_ = dim;
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ',
                      'a', 'd', 's', '<', '>', 'v', '^'};
    // a = artificial intelligence (pod)
    // d = documentation (health pack)
    // s = search (rock)
    int numberOfObjects = 12;

    map_.resize(dim_.y);
    for (int i = 0; i < dim_.y; ++i)
    {
        map_[i].resize(dim_.x);
    }

    for (int i = 0; i < dim_.y; ++i)
    {
        for (int j = 0; j < dim_.x; ++j)
        {
            int objNo = rand() % numberOfObjects;
            map_[i][j] = objects[objNo];
        }
    }
}

int Board::getDimX() const
{
    return dim_.x;
}

int Board::getDimY() const
{
    return dim_.x;
}

char Board::getObject(const Point &position) const
{
    return map_[dim_.y - position.y][position.x - 1];
}

void Board::setObject(const Point &position, char ch)
{
    map_[dim_.y - position.y][position.x - 1] = ch;
}

void Board::setObjectAtCenter(char ch)
{
    map_[dim_.y / 2][dim_.x / 2] = ch;
}

bool Board::isEmpty(const Point &position) const
{
    return map_[dim_.y - position.y][position.x - 1] == ' ';
}

bool Board::isInsideMap(const Point &position) const
{
    bool inMapHorizontally = position.x > 0 && position.x <= dim_.x;
    bool inMapVertically = position.y > 0 && position.y <= dim_.y;
    return inMapHorizontally && inMapVertically;
}

Point Board::getRandomPoint() const
{
    int randomX = rand() % dim_.x + 1;
    int randomY = rand() % dim_.y + 1;

    return Point(randomX, randomY);
}

// Point Board::move(Point &position, char direction, int distance) const
// {
//     switch (direction)
//     {
//     case '^':
//         position.y++;
//         return position;

//     case 'v':
//         position.y--;
//         return position;

//     case '>':
//         position.x++;
//         return position;

//     default:
//         position.x--;
//         return position;
//     }
// }

void Board::display() const
{
#pragma region each row
    for (int i = 0; i < dim_.y; ++i)
    {
        // display upper border of the row
        cout << "  ";
        for (int j = 0; j < dim_.x; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;

        // display row number
        cout << setw(2) << (dim_.y - i);

        // display cell content and border of each column
        for (int j = 0; j < dim_.x; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }
#pragma endregion

#pragma region lower border of the last row
    cout << "  ";
    for (int j = 0; j < dim_.x; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
#pragma endregion

#pragma region column number
    cout << "  ";
    for (int j = 0; j < dim_.x; ++j)
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
    for (int j = 0; j < dim_.x; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
#pragma endregion
}