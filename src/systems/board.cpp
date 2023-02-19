#include "board.h"

Board::Board(Point dim)
{
    trailPoints_ = vector<Point>();
    dim_ = dim;

    initialize();
}

void Board::initialize()
{
    map_.resize(dim_.y);
    for (int y = 0; y < dim_.y; ++y)
    {
        map_[y].resize(dim_.x);
        for (int x = 0; x < dim_.x; ++x)
        {
            map_[y][x] = getRandomObject();
        }
    }
}

void Board::fillUnits(Units &units)
{
    Point center = getCenterPosition();
    setObject(center, units.getPlayerType().getSymbol());

    vector<Point> randomPositions = vector<Point>();

    for (int i = 0; i < units.getEnemiesType().getCount(); ++i)
    {
        Point randomPos = getRandomPoint();
        setObject(randomPos, units.getEnemiesType().getSymbol());
        randomPositions.push_back(randomPos);
    }

    units.fillUnits(center, randomPositions);
}

void Board::display() const
{
#pragma region each row
    for (int y = 0; y < dim_.y; ++y)
    {
        // display upper border of the row
        cout << "  ";
        for (int x = 0; x < dim_.x; ++x)
        {
            cout << "+-";
        }
        cout << "+\n";

        // display row number
        cout << setw(2) << (dim_.y - y);

        // display cell content and border of each column
        for (int x = 0; x < dim_.x; ++x)
        {
            cout << "|" << map_[y][x];
        }
        cout << "|\n";
    }
#pragma endregion

#pragma region lower border of the last row
    cout << "  ";
    for (int x = 0; x < dim_.x; ++x)
    {
        cout << "+-";
    }
    cout << "+\n";
#pragma endregion

#pragma region column number
    cout << "  ";
    for (int x = 0; x < dim_.x; ++x)
    {
        int digit = (x + 1) / 10;
        cout << " ";

        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << "\n  ";
    for (int x = 0; x < dim_.x; ++x)
    {
        cout << " " << (x + 1) % 10;
    }
    cout << "\n\n";
#pragma endregion
}

void Board::spawnFeatures(vector<Unit> *enemies_p)
{
    int featuresToSpawn = 0;

    for (int i = 0; i < enemies_p->size(); i++)
    {
        if (enemies_p->at(i).stats.health == 0)
        {
            featuresToSpawn++;
        }
    }

    for (int i = 1; i <= dim_.y; i++)
    {
        for (int j = 1; j <= dim_.x; j++)
        {
            Point position = Point(j, i);
            cout << position.toString() + "\n";
            if (getObject(position) == 'f')
            {
                featuresToSpawn--;
            }
        }
    }

    while (featuresToSpawn > 0)
    {
        Point position = getRandomPoint();
        char object = getObject(position);

        bool canSpawn = object != 'a' && object != 'P' && object != 'B' && object != 's' && object != 'f' && object != 'c';
        if (canSpawn)
        {
            setObject(position, 'f');
            featuresToSpawn--;
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

int Board::mapX(const Point &position) const
{
    return position.x - 1;
}

int Board::mapY(const Point &position) const
{
    return dim_.y - position.y;
}

char Board::getObject(const Point &position) const
{
    if (!isInsideMap(position))
    {
        throw std::out_of_range("The point: " + position.toString() + " is outside of the map");
    }
    return map_[mapY(position)][mapX(position)];
}

void Board::setObject(const Point &position, char ch)
{
    if (!isInsideMap(position))
    {
        throw std::out_of_range("The point: " + position.toString() + " is outside of the map");
    }
    map_[mapY(position)][mapX(position)] = ch;
}

bool Board::isInsideMap(const Point &position) const
{
    bool isInsideHorizontally = position.x >= 0 && position.x <= dim_.x;
    bool isInsideVertically = position.y >= 0 && position.y <= dim_.y;
    return isInsideHorizontally && isInsideVertically;
}

char Board::getRandomObject() const
{
    int objIndex = rand() % objectsArraySize_;
    return objects[objIndex];
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

void Board::markAsTrial(const Point &position)
{
    setObject(position, trailSymbol_);
    trailPoints_.push_back(position);
}

void Board::clearTrials()
{
    int size = trailPoints_.size();
    for (int i = 0; i < size; ++i)
    {
        int objIndex = rand() % objectsArraySize_;
        Point position = trailPoints_.at(i);

        if (getObject(position) == trailSymbol_)
        {
            setObject(position, objects[objIndex]);
        }
    }

    trailPoints_.clear();
}