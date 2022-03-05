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
}

void Platinum::save_init(void) {
	if (m_has_save)
		m_save = std::make_unique<SavePL>(config::current.platinum_save_path);
	else
		scene::change_scene<File_Explorer>();
}
