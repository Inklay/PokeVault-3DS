#include "./Diamond.hpp"
#include "../config/Config.hpp"
#include "../core/source/Save/Game/SavePL.hpp"

Diamond::Diamond(void) {
	m_has_save = config::current.diamond_save_path == "none";
	m_name = "Pokémon Diamond Version";
	m_box_art = "Diamond.png";
	m_logo = "Diamond.png";
	m_game = ASave::Game::DIAMOND;
}


void Diamond::init_save(void) {

}

void Diamond::set_save(std::string path) {
	m_has_save = path == "none";
	config::current.diamond_save_path = path;
}
