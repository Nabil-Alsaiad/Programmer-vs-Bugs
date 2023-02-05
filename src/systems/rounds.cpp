#include "rounds.h"

Rounds::Rounds()
{
}

bool Rounds::shouldResetRound(const Units &units)
{
    int unitCount = 1 + units.getEnemiesType().getCount();
    bool check = gameRound_ >= unitCount;

    if (check)
    {
        gameRound_ = playerRound_;
    }

    return check;
}

void Rounds::increaseRound()
{
    gameRound_++;
}

bool Rounds::isPlayerRound() const
{
    return gameRound_ == playerRound_;
}

bool Rounds::playEnemyRound(Board &board, Units &units) const
{
    char directions[4] = {'^', 'v', '>', '<'};
    vector<Unit> *enemies_p = units.getEnemiesPointer();
    Unit *player_p = units.getPlayerPointer();

    for (int i = 0; i < enemies_p->size(); i++)
    {
        bool isOwnRound = i == gameRound_ - 1;
        if (isOwnRound)
        {
            int randomIndex = rand() % 4;
            Unit *enemy_p = &(enemies_p->at(i));
            Point oldPosition = enemy_p->position;
            Point newPosition = movePoint(oldPosition, directions[randomIndex]);

            if (canMoveToPosition(board, newPosition, enemy_p))
            {
                finalMove(board, enemy_p, oldPosition, newPosition);
            }

            if (isWithinRange(enemy_p->stats.range, oldPosition, player_p->position))
            {
                return player_p->stats.takeDamage(enemy_p->stats.damage);
            }

            break;
        }
    }

    return false;
}

void Rounds::drawRoundBoard(const Units &units) const
{
    cout << "Units\n-----------------------------------------" << endl;

    int unitCount = 1 + units.getEnemiesType().getCount();
    for (int i = 0; i < unitCount; i++)
    {
        string info;

        if (i == playerRound_)
        {
            info = units.getPlayer().toString();
        }
        else
        {
            info = units.getEnemies().at(i - 1).toString();
        }

        bool isOwnRound = i == gameRound_;
        cout << (isOwnRound ? "-> " : "   ") << info << endl;
    }
}