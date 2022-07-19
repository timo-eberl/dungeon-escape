#include "wall.hpp"

char Wall::print() const { return '|'; }

bool Wall::tryEnter(Player &p) { return false; }

bool Wall::tryLeave(Player &p) { return false; }
