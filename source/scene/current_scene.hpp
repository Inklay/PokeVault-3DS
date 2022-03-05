#ifndef CURRENT_SCENE_HPP
#define CURRENT_SCENE_HPP

#include "./Game_Select.hpp"

namespace scene {
	extern std::unique_ptr<Scene> current_scene;
	extern bool load;

	template<typename T>
	void change_scene() {
		current_scene->unload();
		current_scene = std::make_unique<T>();
		load = true;
	}
}

#endif // !CURRENT_SCENE_HPP
