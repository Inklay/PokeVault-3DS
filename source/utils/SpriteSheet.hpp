#ifndef SPRITESHEET_HPP
#define SPRITESHEET_HPP

#include <map>
#include <string>
#include <utility>
#include <vector>

namespace spritesheet {
    const std::map<std::string, int> game_art = {
        { "Platinum.png", 0 },
        { "Diamond.png", 1 },
        { "Pearl.png", 2 },
        { "HeartGold.png", 3 },
        { "SoulSilver.png", 4 }
    };

    const std::map<std::string, int> game_logo = {
        { "Platinum_EN.png", 0 },
        { "Diamond_EN.png", 1 },
        { "Pearl_EN.png", 2 },
        { "HeartGold_EN.png", 3 },
        { "SoulSilver_EN.png", 4 }
    };
};

#endif // !SPRITESHEET_HPP
