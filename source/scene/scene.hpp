#ifndef SCENES
#define SCENES

#include <vector>
#include <memory>
#include "../UI/UI_Element.hpp"

namespace scene {
	namespace game_select {
		void load(std::vector<std::unique_ptr<UI_Element>>& elem);
		void unload(std::vector<std::unique_ptr<UI_Element>>& elem);
	};
};

#endif // !SCENES
