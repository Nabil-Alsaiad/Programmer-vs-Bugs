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

int Rounds::getEnemyRoundIndex() const
{
    return gameRound_ - 1;
}

bool Rounds::playEnemyRound(Board &board, Unit *player_p, Unit *enemy_p) const
{
    vector<char> directions = {'^', 'v', '>', '<'};

    while (!directions.empty())
    {
        int randomIndex = rand() % directions.size();
        Point newPosition = movePoint(enemy_p->position, directions[randomIndex]);

        bool canMove = canMoveToPosition(board, enemy_p, newPosition);
        if (canMove)
        {
            finalMove(board, enemy_p, newPosition);
            break;
        }

        vector<char>::iterator chosenDirection_it = directions.begin() + randomIndex;
        directions.erase(chosenDirection_it);
    }

    if (isWithinRange(enemy_p, player_p))
    {
        return player_p->stats.takeDamage(enemy_p->stats.damage);
    }

    return false;
}

void Rounds::drawUnitsBoard(const Units &units, bool drawArrow) const
{
    cout << "Units\n-----------------------------------------\n";

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

        bool isOwnRound = drawArrow && (i == gameRound_);
        cout << (isOwnRound ? "-> " : "   ") + info + "\n";
    }
}