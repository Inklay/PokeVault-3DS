#include "./current_game.hpp"

namespace game {
	const std::array<std::shared_ptr<Game>, 5> games = {
		std::make_shared<SoulSilver>(),
		std::make_shared<HeartGold>(),
		std::make_shared<Platinum>(),
		std::make_shared<Pearl>(),
		std::make_shared<Diamond>()
	};

	size_t idx = 2;

	std::shared_ptr<Game> current(void) {
		return games[idx];
	}
};
