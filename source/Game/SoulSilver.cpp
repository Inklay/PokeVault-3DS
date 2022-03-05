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

void SoulSilver::init_save(void) {

}

void SoulSilver::set_save(std::string path) {
	m_has_save = path == "none";
	config::current.soulsilver_save_path = path;
}
