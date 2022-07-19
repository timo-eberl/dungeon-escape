#include <memory>
#include "tile_factory.hpp"
#include "exit.hpp"
#include "floor.hpp"
#include "wall.hpp"
#include "breakable_wall.hpp"
#include "mud.hpp"

std::unique_ptr<ITile> makeTile(int i)
{
    switch (i)
    {
    case 0:
        return std::make_unique<Floor>();
    case 1:
        return std::make_unique<Wall>();
    case 2:
        return std::make_unique<Exit>();
    case 3:
        return std::make_unique<BreakableWall>();
    case 4:
        return std::make_unique<Mud>();
    default:
        return {nullptr};
    }
}

std::vector<std::vector<std::unique_ptr<ITile>>>
generateTiles(const std::vector<std::vector<int>> &map)
{
    std::vector<std::vector<std::unique_ptr<ITile>>> result;
    for (auto &row : map)
    {
        result.push_back({});
        for (auto x : row)
        {
            result.back().push_back(makeTile(x));
        }
    }
    return result;
}
