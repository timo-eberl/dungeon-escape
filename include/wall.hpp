#pragma once

#include "itile.hpp"

class Wall : public ITile
{
public:
    char print() const override;

    bool tryEnter(Player &p) override;

    bool tryLeave(Player &p) override;
};
