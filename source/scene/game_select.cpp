#include "./scene.hpp"
#include "../UI/game_select/Game_Art.hpp"
#include "../UI/Header.hpp"
#include "../Game/Game.hpp"
#include "../Game/all.hpp"
#include "./Game_Select.hpp"
#include "../UI/game_select/Game_Info.hpp"
#include "../Game/current_game.hpp"
#include "./current_scene.hpp"
#include <3ds.h>

void Game_Select::load(std::vector<std::shared_ptr<UI_Element>>& top_elem,
	std::vector<std::shared_ptr<UI_Element>>& bottom_elem) {
	top_elem.clear();
	bottom_elem.clear();
	scene::load = false;

	m_game_art_sheet = C2D_SpriteSheetLoad("romfs:/gfx/game_art.t3x");
	m_game_logo_sheet = C2D_SpriteSheetLoad("romfs:/gfx/game_logo.t3x");

	top_elem.emplace_back(std::make_shared<Header>("Choose a game to open"));

	bool found_compatible_game = false;

	for (size_t i = 0; i < game::games.size(); i++) {
		int x = 24 + 94 * (i % 4);
		int y = 30 + 24 + 94 * (i / 4);
		bool is_locked = !Game::is_compatible(game::games[i]->get_version());
		bool is_selected = false;
		if (!is_locked && !found_compatible_game) {
			is_selected = true;
			found_compatible_game = true;
			game::idx = i;
		}
		top_elem.emplace_back(std::make_shared<Game_Art>(Vec3(x, y, 0),
			game::games[i]->get_box_art(), m_game_art_sheet, button_func::choose_game, is_locked, is_selected));
		if (is_selected) {
			m_selected = std::dynamic_pointer_cast<Button>(top_elem.at(top_elem.size() - 1));
		}
	}
	bottom_elem.emplace_back(std::make_shared<Game_Info>(m_game_logo_sheet));
}

void Game_Select::unload(void) {
	C2D_SpriteSheetFree(m_game_art_sheet);
	C2D_SpriteSheetFree(m_game_logo_sheet);
}

void Game_Select::update(u32 key_down) {
	if (key_down & KEY_A)
		m_selected->pressed();
}
