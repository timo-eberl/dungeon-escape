#include "breakable_wall.hpp"

char BreakableWall::print() const { return state; }

bool BreakableWall::tryEnter(Player &p)
{
    switch (state)
    {
    case 'O':
        state = '0';
        return false;
    case '0':
        state = 'o';
        return false;
    case 'o':
        state = '.';
        return false;
    case '.':
        state = ' ';
        return false;
    default:
        return true;
    }
}

bool BreakableWall::tryLeave(Player &p) { return state == ' '; }
