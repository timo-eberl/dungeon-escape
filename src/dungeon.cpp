#include "dungeon.hpp"
#include "tile_factory.hpp"
#include <algorithm>

Dungeon::Dungeon()
    : player({1, 1}), map(generateTiles({{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                         {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2},
                                         {1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1},
                                         {1, 0, 0, 1, 1, 0, 0, 0, 1, 3, 1},
                                         {1, 0, 0, 1, 1, 1, 0, 0, 1, 3, 1},
                                         {1, 3, 3, 1, 0, 0, 0, 0, 0, 0, 1},
                                         {1, 3, 3, 1, 0, 0, 1, 1, 0, 0, 1},
                                         {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1},
                                         {1, 0, 0, 0, 4, 4, 4, 0, 0, 0, 1},
                                         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}})) {}

Dungeon::~Dungeon() = default;

void Dungeon::printVisibleAreaTo(std::ostream &stream)
{
    stream << visibleAreaStr();
}

std::string Dungeon::visibleAreaStr()
{
    const auto &position = player.position();
    const int fov = player.fov;
    std::string str;

    for (int y = position.y - fov; y <= position.y + fov; ++y)
    {
        for (int x = position.x - fov; x <= position.x + fov; ++x)
        {
            str += charAt({x, y});
        }
        str += '\n';
    }

    return str;
}

char Dungeon::charAt(Vector2D position)
{
    char characterToPrint;

    if (isOutOfBounds(position))
    {
        return ' ';
    }
    if (position == player.position())
    {
        return player.print();
    }
    return map[position.y][position.x]->print();
}

bool Dungeon::moveLeft()
{
    const auto &position = player.position();
    Vector2D newPosition = {std::max(0, position.x - 1), position.y};
    return move(position, newPosition);
}

bool Dungeon::moveRight()
{
    const auto &position = player.position();
    Vector2D newPosition = {std::min((int)map[position.y].size() - 1, position.x + 1), position.y};
    return move(position, newPosition);
}

bool Dungeon::moveUp()
{
    const auto &position = player.position();
    Vector2D newPosition = {position.x, std::max(0, position.y - 1)};
    return move(position, newPosition);
}

bool Dungeon::moveDown()
{
    const auto &position = player.position();
    Vector2D newPosition = {position.x, std::min((int)map.size() - 1, position.y + 1)};
    return move(position, newPosition);
}

bool Dungeon::move(Vector2D oldPosition, Vector2D newPosition)
{
    if (!canMove(oldPosition, newPosition))
    {
        return false;
    }

    player.moveTo(newPosition);

    return isGoal(newPosition);
}

bool Dungeon::canMove(Vector2D oldPosition, Vector2D newPosition)
{
    ITile &oldTile = *map[oldPosition.y][oldPosition.x];
    bool isStuck = !oldTile.tryLeave(player);
    if (isStuck)
    {
        return false;
    }

    ITile &newTile = *map[newPosition.y][newPosition.x];
    bool hitsWall = !newTile.tryEnter(player);
    return !hitsWall;
}

bool Dungeon::isGoal(Vector2D position)
{
    return map[position.y][position.x]->isGoal();
}

bool Dungeon::isOutOfBounds(Vector2D position)
{
    int x = position.x;
    int y = position.y;

    int height = map.size();
    if (y < 0 || y >= height)
    {
        return true;
    }

    int width = map[y].size();
    if (x < 0 || x >= width)
    {
        return true;
    }

    return false;
}
