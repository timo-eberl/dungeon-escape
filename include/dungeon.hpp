#pragma once

#include <string>
#include "player.hpp"
#include "vector2d.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include "itile.hpp"

class Dungeon
{
private:
    std::vector<std::vector<std::unique_ptr<ITile>>> map;

    Player player;

    char charAt(Vector2D position);

    bool move(Vector2D oldPosition, Vector2D newPosition);

    bool canMove(Vector2D oldPosition, Vector2D newPosition);

    bool isGoal(Vector2D position);

    bool isOutOfBounds(Vector2D position);

public:
    void printVisibleAreaTo(std::ostream &stream);

    std::string visibleAreaStr();

    bool moveUp();

    bool moveLeft();

    bool moveDown();

    bool moveRight();

    Dungeon();

    ~Dungeon();
};
