#pragma once

#include <cmath>

struct Vector2D
{
    int x, y;

    Vector2D &operator+=(Vector2D rhs);

    Vector2D &operator-=(Vector2D rhs);

    Vector2D &operator*=(Vector2D rhs);

    Vector2D &operator+=(int rhs);

    Vector2D &operator-=(int rhs);

    Vector2D &operator*=(int rhs);
};

Vector2D operator+(Vector2D lhs, Vector2D rhs);

Vector2D operator-(Vector2D lhs, Vector2D rhs);

Vector2D operator*(Vector2D lhs, Vector2D rhs);

Vector2D operator+(int lhs, Vector2D rhs);

Vector2D operator-(int lhs, Vector2D rhs);

Vector2D operator*(int lhs, Vector2D rhs);

Vector2D operator+(Vector2D lhs, int rhs);

Vector2D operator-(Vector2D lhs, int rhs);

Vector2D operator*(Vector2D lhs, int rhs);

bool operator==(Vector2D lhs, Vector2D rhs);

bool operator!=(Vector2D lhs, Vector2D rhs);
