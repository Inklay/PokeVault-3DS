#ifndef SCENES
#define SCENES

#include <vector>
#include <memory>
#include "../UI/UI_Element.hpp"

namespace scene {
	namespace game_select {
		void load(std::vector<std::unique_ptr<UI_Element>>& top_elem,
			std::vector<std::unique_ptr<UI_Element>>& bottom_elem);
		void unload(std::vector<std::unique_ptr<UI_Element>>& top_elem,
			std::vector<std::unique_ptr<UI_Element>>& bottom_elem);
	};
};

#endif // !SCENES
