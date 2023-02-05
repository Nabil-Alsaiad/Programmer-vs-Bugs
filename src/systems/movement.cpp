#pragma once

#include <cmath>
#include <iostream>
#include "point.h"
#include "board.h"
#include "../units/unit.h"

using namespace std;

bool isWithinRange(const int range, const Point &originalPosition, const Point &targetPosition)
{
    bool isWithinX = abs(targetPosition.x - originalPosition.x) <= range;
    bool isWithinY = abs(targetPosition.y - originalPosition.y) <= range;

    return isWithinX && isWithinY;
}

Point movePoint(Point position, char direction)
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

void finalMove(Board &board, Unit *unit_p, const Point &oldPosition, const Point &newPosition)
{
    board.setObject(newPosition, unit_p->TYPE_P->getSymbol());
    unit_p->position = newPosition;

    board.markAsTrial(oldPosition);
}

bool canMoveToPosition(Board &board, const Point &newPosition, Unit *unit_p, vector<Unit> *enemies_p = {}, bool isPlayer = true)
{
    bool isInside = board.isInsideMap(newPosition);
    if (!isInside)
    {
        return false;
    }

    char objAtPosition = board.getObject(newPosition);

    bool isSearch = objAtPosition == 's';
    if (isSearch)
    {
        board.setObject(newPosition, board.getRandomObject());
    }

    bool isUnit = objAtPosition == 'P' || objAtPosition == 'B';
    if (isUnit && isPlayer)
    {
        int size = enemies_p->size();

        Unit *enemy_p;
        for (int i = 0; i < size; i++)
        {
            enemy_p = &(enemies_p->at(i));
            if (enemy_p->position.isEqual(newPosition))
            {
                break;
            }
        }

        bool enemyDied = enemy_p->stats.takeDamage(unit_p->stats.damage);
        return enemyDied;
    }

    return !isSearch && !isUnit;
}

void movePlayer(Board &board, Units &units, char direction)
{
    Unit *player_p = units.getPlayerPointer();

    while (true)
    {
        Point oldPosition = player_p->position;
        Point newPosition = movePoint(oldPosition, direction);
        if (!canMoveToPosition(board, newPosition, player_p, units.getEnemiesPointer()))
        {
            break;
        }

        char objAtPosition = board.getObject(newPosition);
        if (objAtPosition == '^' || objAtPosition == 'v' || objAtPosition == '>' || objAtPosition == '<')
        {
            direction = objAtPosition;
            player_p->stats.damage += 20;
        }
        if (objAtPosition == 'f')
        {
            player_p->stats.damage *= 2;
        }

        finalMove(board, player_p, oldPosition, newPosition);
    }

    player_p->stats.damage = 0;
}