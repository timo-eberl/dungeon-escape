#include "player.hpp"

Player::Player(Vector2D position)
    : m_position(position), m_previousPosition({position.x - 1, position.y}) {}

Vector2D Player::position() const { return m_position; }

void Player::moveTo(Vector2D position)
{
    if (position != m_position)
    {
        m_previousPosition = m_position;
    }
    m_position = position;
}

char Player::print() const
{
    if (m_previousPosition.x < m_position.x)
    {
        return '>';
    }
    if (m_previousPosition.x > m_position.x)
    {
        return '<';
    }
    if (m_previousPosition.y < m_position.y)
    {
        return 'v';
    }
    if (m_previousPosition.y > m_position.y)
    {
        return '^';
    }
    return '>';
}
