#ifndef SCENES_HPP
#define SCENES_HPP

#include <vector>
#include <memory>
#include "../UI/Button.hpp"
#include "../utils/button_func.hpp"

class Scene {
public:
	virtual void load(std::vector<std::shared_ptr<UI_Element>>& top_elem,
		std::vector<std::shared_ptr<UI_Element>>& bottom_elem) = 0;
	virtual void unload(void) = 0;
	virtual void update(std::vector<std::shared_ptr<UI_Element>>& top_elem,
		std::vector<std::shared_ptr<UI_Element>>& bottom_elem, u32 key_down) = 0;
};

#endif // !SCENES_HPP
