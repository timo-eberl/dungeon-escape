#pragma once

#include "itile.hpp"

class Mud : public ITile
{
private:
    int leaveTries{0};
    const int requiredLeaveTries{2};

public:
    char print() const override;

    bool tryEnter(Player &player) override;

    bool tryLeave(Player &player) override;
};
