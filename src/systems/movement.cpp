#pragma once

#include <cmath>
#include <iostream>
#include "point.h"
#include "board.h"
#include "../units/unit.h"

using namespace std;

bool isWithinRange(const Unit *attacker, const Unit *target)
{
    bool isWithinX = abs(target->position.x - attacker->position.x) <= attacker->stats.range;
    bool isWithinY = abs(target->position.y - attacker->position.y) <= attacker->stats.range;

    return isWithinX && isWithinY;
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
        cout << "Received invalid direction\n";
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

char checkObj(Board &board, Units &units, Point &newPosition, Unit *player_p, char direction)
{
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
    else if (objAtPosition == 'c')
    {
        player_p->stats.heal(20);
    }
    else if (objAtPosition == 'a')
    {
        Point deadEnemyPosition = units.attackClosestEnemy(newPosition);
        if (!deadEnemyPosition.isNull())
        {
            board.setObject(deadEnemyPosition, ' ');
        }
    }

    return direction;
}

void movePlayer(Board &board, Units &units, char direction)
{
    Unit *player_p = units.getPlayerPointer();
    vector<Unit> *enemies_p = units.getEnemiesPointer();

    while (true)
    {
        Point newPosition = movePoint(player_p->position, direction);
        if (!canMoveToPosition(board, player_p, newPosition, enemies_p))
        {
            break;
        }

        direction = checkObj(board, units, newPosition, player_p, direction);
        finalMove(board, player_p, newPosition);
    }

    player_p->stats.damage = 0;
}