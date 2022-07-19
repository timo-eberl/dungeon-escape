#pragma once

class Player;

struct ITile
{
    virtual char print() const = 0;

    virtual bool tryEnter(Player &player);

    virtual bool tryLeave(Player &player);

    virtual bool isGoal() const;

    virtual ~ITile() = default;
};
