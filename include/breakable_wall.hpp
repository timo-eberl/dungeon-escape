#pragma once

#include "itile.hpp"

class BreakableWall : public ITile
{
private:
    char state{'O'};

public:
    char print() const override;

    bool tryEnter(Player &p) override;

    bool tryLeave(Player &p) override;
};
