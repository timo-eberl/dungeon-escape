#pragma once

#include "vector2d.hpp"

class Player
{
public:
    Player(Vector2D position);

    Vector2D position() const;

    const int fov{3};

    void moveTo(Vector2D position);

    char print() const;

private:
    Vector2D m_position;
    Vector2D m_previousPosition;
};
