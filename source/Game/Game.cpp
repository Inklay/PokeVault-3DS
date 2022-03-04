#include "./Game.hpp"

bool Game::has_save(void) {
	return m_has_save;
}

std::string Game::get_name(void) {
	return m_name;
}

std::string Game::get_box_art(void) {
	return m_box_art;
}

std::string Game::get_logo(void) {
	return m_logo;
}

bool Game::is_compatible(std::string name) {
	return name == "Platinum";
}
