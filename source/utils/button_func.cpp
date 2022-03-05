#include "./button_func.hpp"
#include "../Game/current_game.hpp"
#include "../config/Config.hpp"

namespace button_func {
	void choose_game(void) {
		game::current()->open_save();
	}

	void choose_save(std::string path) {
		game::current()->set_save(path);
		config::current.save();
	}
};
