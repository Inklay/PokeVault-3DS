#include "./SoulSilver.hpp"
#include "../config/Config.hpp"
#include "../core/source/Save/Game/SavePL.hpp"

SoulSilver::SoulSilver(void) {
	m_has_save = config::current.soulsilver_save_path == "none";
	m_name = "Pokémon Soul Silver Version";
	m_box_art = "SoulSilver.png";
	m_logo = "SoulSilver.png";
	m_game = ASave::Game::SOULSILVER;
}

void SoulSilver::save_init(void) {
	//m_save = std::make_unique<SavePL>(config::current.platinum_save_path);
}
