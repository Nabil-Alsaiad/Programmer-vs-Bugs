#pragma once

#include <cmath>
#include <iostream>
#include "point.h"
#include "board.h"
#include "../units/unit.h"

using namespace std;

bool isWithinRange(const Point &originalPosition, const Point &targetPosition, const int range)
{
    bool isWithinX = abs(targetPosition.x - originalPosition.x) <= range;
    bool isWithinY = abs(targetPosition.y - originalPosition.y) <= range;

    return isWithinX && isWithinY;
}
bool isWithinRange(const Unit *attacker, const Unit *target)
{
    return isWithinRange(attacker->position, target->position, attacker->stats.range);
}

Point movePoint(const Point &position, const char direction)
{
    switch (direction)
    {
    case '^':
        return Point(position.x, position.y + 1);

    case 'v':
        return Point(position.x, position.y - 1);

    case '>':
        return Point(position.x + 1, position.y);

    case '<':
        return Point(position.x - 1, position.y);

    default:
        cout << "Received invalid direction" << endl;
        return position;
    }
}

void finalMove(Board &board, Unit *unit_p, const Point &newPosition)
{
    board.markAsTrial(unit_p->position);

    board.setObject(newPosition, unit_p->TYPE_P->getSymbol());
    unit_p->position = newPosition;
}

bool canMoveToPosition(Board &board, Unit *unit_p, const Point &newPosition, vector<Unit> *enemies_p = {})
{
    bool isInside = board.isInsideMap(newPosition);
    if (!isInside)
    {
        return false;
    }

    char objAtPosition = board.getObject(newPosition);

    bool isSearch = objAtPosition == 's';
    bool isUnit = objAtPosition == 'P' || objAtPosition == 'B';

    if (isSearch)
    {
        board.setObject(newPosition, board.getRandomObject());
        return !enemies_p;
    }
    else if (isUnit)
    {
        if (enemies_p)
        {
            for (int i = 0; i < enemies_p->size(); ++i)
            {
                Unit *enemy_p = &(enemies_p->at(i));
                if (enemy_p->position.isEqual(newPosition))
                {
                    bool enemyDied = enemy_p->stats.takeDamage(unit_p->stats.damage);
                    return enemyDied;
                }
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}

void movePlayer(Board &board, Units &units, char direction)
{
    Unit *player_p = units.getPlayerPointer();

    while (true)
    {
        Point oldPosition = player_p->position;
        Point newPosition = movePoint(oldPosition, direction);
        if (!canMoveToPosition(board, player_p, newPosition, units.getEnemiesPointer()))
        {
            break;
        }

        char objAtPosition = board.getObject(newPosition);
        if (objAtPosition == '^' || objAtPosition == 'v' || objAtPosition == '>' || objAtPosition == '<')
        {
            direction = objAtPosition;
            player_p->stats.damage += 20;
        }
        else if (objAtPosition == 'f')
        {
            player_p->stats.damage *= 2;
        }

        finalMove(board, player_p, newPosition);
    }

    player_p->stats.damage = 0;
}