#include "./scene.hpp"
#include "../UI/Game_Art.hpp"
#include "../UI/Header.hpp"
#include "../UI/Background.hpp"
#include "../Game/Game.hpp"
#include "./Game_Select.hpp"

void Game_Select::load(std::vector<std::unique_ptr<UI_Element>>& top_elem,
	std::vector<std::unique_ptr<UI_Element>>& bottom_elem) {
	m_sheet = C2D_SpriteSheetLoad("romfs:/gfx/game_art.t3x");

	top_elem.emplace_back(std::make_unique<Background>(Background::Screen::TOP));
	top_elem.emplace_back(std::make_unique<Header>("Choose a game to open"));

	bool found_compatible_game = false;

	for (size_t i = 0; i < m_games.size(); i++) {
		int x = 24 + 94 * (i % 4);
		int y = 30 + 24 + 94 * (i / 4);
		bool is_locked = !Game::is_compatible(m_games[i].first);
		bool is_selected = false;
		if (!is_locked && !found_compatible_game) {
			is_selected = true;
			found_compatible_game = true;
		}
		top_elem.emplace_back(std::make_unique<Game_Art>(Vec3(x, y, 0),
			m_games[i].first, m_games[i].second, m_sheet, is_locked, is_selected));
	}

	bottom_elem.emplace_back(std::make_unique<Background>(Background::Screen::BOTTOM));
}

void Game_Select::unload(void) {
	C2D_SpriteSheetFree(m_sheet);
}

#ifndef GAME_LIST
#define GAME_LIST

const std::array<std::pair<std::string, std::string>, 5> Game_Select::m_games = {
		std::pair<std::string, std::string>("Soul Silver" , "SoulSilver.png"),
		std::pair<std::string, std::string>("Heart Gold" , "HeartGold.png"),
		std::pair<std::string, std::string>("Platinum" , "Platinum.png"),
		std::pair<std::string, std::string>("Pearl" , "Pearl.png"),
		std::pair<std::string, std::string>("Diamond" , "Diamond.png"),
};

#endif // !GAME_LIST
