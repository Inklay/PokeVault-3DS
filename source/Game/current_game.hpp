#ifndef CURRENT_GAME_HPP
#define CURRENT_GAME_HPP

#include "./Game.hpp"
#include <array>
#include "./all.hpp"

namespace game {
	std::shared_ptr<Game> current(void);
	extern size_t idx;
	extern const std::array<std::shared_ptr<Game>, 5> games;
}

#endif // !CURRENT_GAME_HPP
