#include "./File_Explorer.hpp"
#include "./current_scene.hpp"
#include "../UI/Header.hpp"
#include "../Game/current_game.hpp"

void File_Explorer::load(std::vector<std::shared_ptr<UI_Element>>& top_elem,
	std::vector<std::shared_ptr<UI_Element>>& bottom_elem) {
	top_elem.clear();
	bottom_elem.clear();
	scene::load = false;

	m_game_logo_sheet = C2D_SpriteSheetLoad("romfs:/gfx/game_logo.t3x");

	top_elem.emplace_back(std::make_shared<Header>("Opening save for " + game::current()->get_name()));

}

void File_Explorer::unload(void) {

}

void File_Explorer::update_inputs(u32 key_down) {

}