#include "mud.hpp"

char Mud::print() const { return '~'; }

bool Mud::tryEnter(Player &player)
{
    leaveTries = 0;
    return true;
}

bool Mud::tryLeave(Player &player)
{
    leaveTries++;
    if (leaveTries >= requiredLeaveTries)
    {
        leaveTries = 0;
        return true;
    }
    return false;
}
