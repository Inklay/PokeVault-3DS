#ifndef CURRENT_SCENE_HPP
#define CURRENT_SCENE_HPP

#include "./Game_Select.hpp"

namespace scene {
	static std::unique_ptr<Scene> current_scene = std::make_unique<Game_Select>();

	template<typename T>
	void change_scene(Scene& new_scene, std::vector<std::unique_ptr<UI_Element>>& top_elem,
		std::vector<std::unique_ptr<UI_Element>>& bottom_elem) {
		current_scene->unload();
		top_elem.clear();
		bottom_elem.clear();
		current_scene = std::make_unique<T>(new_scene);
		current_scene->load(top_elem, bottom_elem);
	}
}

#endif // !CURRENT_SCENE_HPP
