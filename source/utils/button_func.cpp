#include "./button_func.hpp"
#include "../Game/current_game.hpp"

namespace button_func {
	void choose_game(void) {
		game::current()->save_init();
	}
};
