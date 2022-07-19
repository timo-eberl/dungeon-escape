#pragma once

#include "itile.hpp"
#include <vector>
#include <memory>

std::unique_ptr<ITile> makeTile(int i);

std::vector<std::vector<std::unique_ptr<ITile>>>
generateTiles(const std::vector<std::vector<int>> &map);
