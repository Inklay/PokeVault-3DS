#include "./SpriteSheet.hpp"

namespace spritesheet {
	std::pair<int, int> get_pokemon_sprite(std::string file_name) {
		for (size_t i = 0; i < pkm.size(); i++) {
			if (pkm.at(i).find(file_name) != pkm.at(i).end()) {
				return std::pair<int, int>(i, pkm.at(i).at(file_name));
			}
		}
		return std::pair<int, int>(0, 2);
	}
};
