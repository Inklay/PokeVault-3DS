#include "./Game.hpp"
#include "../scene/current_scene.hpp"
#include "../scene/File_Explorer.hpp"

void Game::open_save(void) {
	if (!m_has_save)
		scene::change_scene<File_Explorer>();
}

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

std::string Game::get_file_extension(void) {

	return m_file_extension;
}

bool Game::is_compatible(ASave::Game game_version) {
	return game_version == ASave::Game::PLATINUM;
}
