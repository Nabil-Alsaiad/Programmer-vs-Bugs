#ifndef BOARD_H
#define BOARD_H

#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include "point.h"
#include "units.h"
#include "../pf/helper.h"

using namespace std;
using namespace pf;

class Board
{
private:
    vector<vector<char>> map_;
    vector<Point> trailPoints_;
    Point dim_;

    char trailSymbol_ = '.';
    int objectsArraySize_ = 19;
    char objects[19] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', 's', 'c', 'a', 'a', '<', '<', '>', '>', 'v', 'v', '^', '^'};

public:
    Board(Point dim = Point(13, 5));
    void initialize();
    void fillUnits(Units &units);
    void display() const;
    bool spawnFeatures(vector<Unit> *enemies_p);

    int getDimX() const;
    int getDimY() const;
    int mapX(const Point &position) const;
    int mapY(const Point &position) const;

    char getObject(const Point &position) const;
    void setObject(const Point &position, char ch);
    bool isInsideMap(const Point &position) const;

    char getRandomObject() const;
    Point getRandomPoint() const;
    Point getCenterPosition() const;

    void markAsTrial(const Point &position);
    void clearTrials();
};

#endif