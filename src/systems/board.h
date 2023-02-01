#ifndef BOARD_H
#define BOARD_H

#pragma once

#include "point.h"
#include <vector>

using namespace std;

class Board
{
private:
    vector<vector<char>> map_;
    int dimX_, dimY_;

public:
    Board(int dimX = 15, int dimY = 5);
    void init(int dimX, int dimY);
    void display() const;

    int getDimX() const;
    int getDimY() const;

    char getObject(Point position) const;
    void setObject(Point position, char ch);
    void setObjectAtCenter(char ch);

    bool isEmpty(Point position) const;
    bool isInsideMap(Point position) const;

    Point getRandomPoint() const;
};

#endif