#include "./Pearl.hpp"
#include "../config/Config.hpp"
#include "../core/source/Save/Game/SavePL.hpp"

Pearl::Pearl(void) {
	m_has_save = config::current.pearl_save_path == "none";
	m_name = "Pokémon Pearl Version";
	m_box_art = "Pearl.png";
	m_logo = "Pearl.png";
	m_game = ASave::Game::PEARL;
}

void Pearl::save_init(void) {
	//m_save = std::make_unique<SavePL>(config::current.PL_save_path);
}
