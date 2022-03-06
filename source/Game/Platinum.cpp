#include "./Platinum.hpp"
#include "../config/Config.hpp"
#include "../core/source/Save/Game/SavePL.hpp"
#include "../scene/File_Explorer.hpp"

Platinum::Platinum(void) {
	m_has_save = config::current.platinum_save_path != "none";
	m_name = "Pokémon Platinum Version";
	m_box_art = "Platinum.png";
	m_logo = "Platinum_EN.png";
	m_game = ASave::Game::PLATINUM;
	m_file_extension = ".SAV";
}

void Platinum::init_save(void) {
	if (m_has_save && !m_is_init) {
		save = std::make_unique<SavePL>(config::current.platinum_save_path);
		save->init(config::current.platinum_save_path);
		m_is_init = true;
	}
}

void Platinum::set_save(std::string path) {
	m_has_save = path != "none";
	config::current.platinum_save_path = path;
	if (m_has_save) {
		m_is_init = false;
		init_save();
	}
}
