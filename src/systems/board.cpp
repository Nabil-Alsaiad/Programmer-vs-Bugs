#include "board.h"
#include "point.h"
#include <iostream>
#include <iomanip>

using namespace std;

Board::Board(Units *units, Point dim)
{
    units_p = units;
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

int Board::checkDimX(int x) const
{
    if (x < 0)
    {
        x = 0;
    }
    else if (x >= dim_.x)
    {
        x = dim_.x;
    }

    return x;
}

int Board::checkDimY(int y) const
{
    if (y < 0)
    {
        y = 0;
    }
    else if (y >= dim_.y)
    {
        y = dim_.y;
    }

    return y;
}

char Board::getObject(const Point &position) const
{
    int x = position.x - 1;
    int y = dim_.y - position.y;
    return map_[checkDimY(y)][checkDimX(x)];
}

void Board::setObject(const Point &position, char ch)
{
    int x = position.x - 1;
    int y = dim_.y - position.y;
    map_[checkDimY(y)][checkDimX(x)] = ch;
}

bool Board::isEmpty(const Point &position) const
{
    int x = position.x - 1;
    int y = dim_.y - position.y;
    return map_[checkDimY(y)][checkDimX(x)] == ' ';
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

Point Board::getCenterPosition() const
{
    return Point((dim_.x / 2) + 1, (dim_.y / 2) + 1);
}

void Board::movePlayer(char direction)
{
    Point playerPos = units_p->getPlayer().getPosition();

    // cout << "playerPos: " + playerPos.toString() << endl;

    Point newPlayerPos = movePosition(playerPos, direction);
    if (!isInsideMap(newPlayerPos))
    {
        return;
    }

    // cout << "newPlayerPos: " + newPlayerPos.toString() << endl;

    char objAtNewPlayerPos = getObject(newPlayerPos);

    // cout << "objAtNewPlayerPos: " + objAtNewPlayerPos << endl;

    setObject(newPlayerPos, units_p->getPlayerType().getSymbol());

    units_p->getPlayer().setPosition(newPlayerPos);

    // if (objAtNewPlayerPos == ' ')
    // {
    // }
    // cout << "Moved player from point: " + playerPos.toString() + " to point: " + newPlayerPos.toString() + " which included: " << objAtNewPlayerPos << endl;
}

Point Board::movePosition(Point position, char direction) const
{
    switch (direction)
    {
    case '^':
        position.y++;
        return position;

    case 'v':
        position.y--;
        return position;

    case '>':
        position.x++;
        return position;

    case '<':
        position.x--;
        return position;

    default:
        cout << "Received invalid direction" << endl;
        return position;
    }
}

void Board::fillUnits()
{
    Point center = getCenterPosition();
    setObject(center, units_p->getPlayerType().getSymbol());

    vector<Point> randomPositions = vector<Point>();

    for (int i = 0; i < units_p->getEnemiesType().getCount(); i++)
    {
        Point randomPos = getRandomPoint();
        setObject(randomPos, units_p->getEnemiesType().getSymbol());
        randomPositions.push_back(randomPos);
    }

    units_p->fillUnits(center, randomPositions);
}

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