#include "./File_Explorer.hpp"
#include "./current_scene.hpp"

void File_Explorer::load(std::vector<std::shared_ptr<UI_Element>>& top_elem,
	std::vector<std::shared_ptr<UI_Element>>& bottom_elem) {
	top_elem.clear();
	bottom_elem.clear();
	scene::load = false;
}

void File_Explorer::unload(void) {

}

void File_Explorer::update_inputs(u32 key_down) {

}
