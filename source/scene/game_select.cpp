#include "./scene.hpp"
#include "../UI/Game_Art.hpp"
#include "../UI/Header.hpp"
#include "../Game/Game.hpp"
#include "../Game/all.hpp"
#include "./Game_Select.hpp"

void Game_Select::load(std::vector<std::unique_ptr<UI_Element>>& top_elem,
	std::vector<std::unique_ptr<UI_Element>>& bottom_elem) {
	m_sheet = C2D_SpriteSheetLoad("romfs:/gfx/game_art.t3x");
	const std::array<std::unique_ptr<Game>, 5> games = {
		std::make_unique<SoulSilver>(),
		std::make_unique<HeartGold>(),
		std::make_unique<Platinum>(),
		std::make_unique<Pearl>(),
		std::make_unique<Diamond>()
	};

	top_elem.emplace_back(std::make_unique<Header>("Choose a game to open"));

	bool found_compatible_game = false;

	for (size_t i = 0; i < games.size(); i++) {
		int x = 24 + 94 * (i % 4);
		int y = 30 + 24 + 94 * (i / 4);
		bool is_locked = !Game::is_compatible(games[i]->get_version());
		bool is_selected = false;
		if (!is_locked && !found_compatible_game) {
			is_selected = true;
			found_compatible_game = true;
		}
		top_elem.emplace_back(std::make_unique<Game_Art>(Vec3(x, y, 0),
			games[i]->get_box_art(), m_sheet, is_locked, is_selected));
	}
}

void Game_Select::unload(void) {
	C2D_SpriteSheetFree(m_sheet);
}
