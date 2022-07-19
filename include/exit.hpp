#pragma once

#include "itile.hpp"

class Exit : public ITile
{
public:
    char print() const override;

    bool isGoal() const override;
};
