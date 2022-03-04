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

ASave::Game Game::get_version(void) {
	return m_game;
}

bool Game::is_compatible(ASave::Game game_version) {
	return game_version == ASave::Game::PLATINUM;
}
