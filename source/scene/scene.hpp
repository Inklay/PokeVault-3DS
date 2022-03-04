#ifndef SCENES_HPP
#define SCENES_HPP

#include <vector>
#include <memory>
#include "../UI/Button.hpp"

class Scene {
public:
	virtual void load(std::vector<std::shared_ptr<UI_Element>>& top_elem,
		std::vector<std::shared_ptr<UI_Element>>& bottom_elem) = 0;
	virtual void unload(void) = 0;

protected:
	std::shared_ptr<Button> m_selected;
};

#endif // !SCENES_HPP
