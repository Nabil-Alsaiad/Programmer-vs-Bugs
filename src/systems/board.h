#ifndef BOARD_H
#define BOARD_H

#pragma once

#include "point.h"
#include "units.h"
#include <vector>

using namespace std;

class Board
{
private:
    Units *units_p;
    vector<vector<char>> map_;
    Point dim_;

public:
    Board(Units *units, Point dim = Point(15, 5));
    void init(const Point &dim);
    void display() const;
    void fillUnits();

    int getDimX() const;
    int getDimY() const;
    int checkDimX(int x) const;
    int checkDimY(int y) const;

    char getObject(const Point &position) const;
    void setObject(const Point &position, char ch);

    bool isEmpty(const Point &position) const;
    bool isInsideMap(const Point &position) const;

    Point getRandomPoint() const;
    Point getCenterPosition() const;

    void movePlayer(char direction);
    Point movePosition(Point position, char direction) const;
};

#endif