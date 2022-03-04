#ifndef SCENES_HPP
#define SCENES_HPP

#include <vector>
#include <memory>
#include "../UI/UI_Element.hpp"

class Scene {
public:
	virtual void load(std::vector<std::unique_ptr<UI_Element>>& top_elem,
		std::vector<std::unique_ptr<UI_Element>>& bottom_elem) = 0;
	virtual void unload(void) = 0;
};

#endif // !SCENES_HPP
