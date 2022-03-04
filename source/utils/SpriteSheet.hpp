#ifndef SPRITESHEET
#define SPRITESHEET

#include <map>
#include <string>

namespace spritesheet {
    static const std::map<std::string, int> game_art = {
        { "Platinum.png", 0 },
        { "Diamond.png", 1 },
        { "Pearl.png", 2 },
        { "HeartGold.png", 3 },
        { "SoulSilver.png", 4 }
    };
};

#endif // !SPRITESHEET
