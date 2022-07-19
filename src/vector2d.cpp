#include "vector2d.hpp"

Vector2D &Vector2D::operator+=(Vector2D rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Vector2D &Vector2D::operator-=(Vector2D rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

Vector2D &Vector2D::operator*=(Vector2D rhs)
{
    x *= rhs.x;
    y *= rhs.y;
    return *this;
}

Vector2D &Vector2D::operator+=(int rhs)
{
    x += rhs;
    y += rhs;
    return *this;
}

Vector2D &Vector2D::operator-=(int rhs)
{
    x -= rhs;
    y -= rhs;
    return *this;
}

Vector2D &Vector2D::operator*=(int rhs)
{
    x *= rhs;
    y *= rhs;
    return *this;
}

Vector2D operator+(Vector2D lhs, Vector2D rhs)
{
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}

Vector2D operator-(Vector2D lhs, Vector2D rhs)
{
    return {lhs.x - rhs.x, lhs.y - rhs.y};
}

Vector2D operator*(Vector2D lhs, Vector2D rhs)
{
    return {lhs.x * rhs.x, lhs.y * rhs.y};
}

Vector2D operator+(int lhs, Vector2D rhs) { return {lhs + rhs.x, lhs + rhs.y}; }

Vector2D operator-(int lhs, Vector2D rhs) { return {lhs - rhs.x, lhs - rhs.y}; }

Vector2D operator*(int lhs, Vector2D rhs) { return {lhs * rhs.x, lhs * rhs.y}; }

Vector2D operator+(Vector2D lhs, int rhs) { return {lhs.x + rhs, lhs.y + rhs}; }

Vector2D operator-(Vector2D lhs, int rhs) { return {lhs.x - rhs, lhs.y - rhs}; }

Vector2D operator*(Vector2D lhs, int rhs) { return {lhs.x * rhs, lhs.y * rhs}; }

bool operator==(Vector2D lhs, Vector2D rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator!=(Vector2D lhs, Vector2D rhs) { return !(lhs == rhs); }
