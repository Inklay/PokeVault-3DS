#include "./Box_View.hpp"
#include "../Game/current_game.hpp"

Box_View::Box_View(void) :
m_box(game::current()->save->get_current_box()) {
}

void Box_View::load(std::vector<std::shared_ptr<UI_Element>>& top_elem,
std::vector<std::shared_ptr<UI_Element>>& bottom_elem) {

}

void Box_View::unload(void) {

}

void Box_View::update(std::vector<std::shared_ptr<UI_Element>>& top_elem,
std::vector<std::shared_ptr<UI_Element>>& bottom_elem, u32 key_down) {

}
