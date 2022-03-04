#include "./HeartGold.hpp"
#include "../config/Config.hpp"
#include "../core/source/Save/Game/SavePL.hpp"

HeartGold::HeartGold(void) {
	m_has_save = config::current.heartgold_save_path == "none";
	m_name = "Pokémon Heart Gold Version";
	m_box_art = "HeartGold.png";
	m_logo = "HeartGold.png";
	m_game = ASave::Game::HEARTGOLD;
}

void HeartGold::save_init(void) {
	//m_save = std::make_unique<SavePL>(config::current.PL_save_path);
}
