#include "./Box_View.hpp"
#include "../Game/current_game.hpp"
#include "../UI/box_view/Box.hpp"
#include "../scene/Game_Select.hpp"
#include "../utils/SpriteSheet.hpp"

Box_View::Box_View(void) :
m_box(game::current()->save->get_current_box()) {
	m_name = "Box View";
}

void Box_View::load(std::vector<std::shared_ptr<UI_Element>>& top_elem,
std::vector<std::shared_ptr<UI_Element>>& bottom_elem) {
	top_elem.clear();
	bottom_elem.clear();
	scene::load = false;

	top_elem.emplace_back(std::make_shared<Box>(true, game::current()->save->get_current_box(), GFX_TOP));

	bottom_elem.emplace_back(std::make_shared<Box>(false, game::current()->save->get_current_box(), GFX_BOTTOM));
}

void Box_View::unload(void) {

}

void Box_View::update(std::vector<std::shared_ptr<UI_Element>>& top_elem,
std::vector<std::shared_ptr<UI_Element>>& bottom_elem, u32 key_down) {
	if (key_down & KEY_START) {
		scene::change_scene<Game_Select>();
		return;
	}
}
