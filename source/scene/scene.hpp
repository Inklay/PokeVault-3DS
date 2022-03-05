#ifndef SCENES_HPP
#define SCENES_HPP

#include <vector>
#include <memory>
#include "../UI/AButton.hpp"
#include "../utils/button_func.hpp"

class Scene {
public:
	virtual void load(std::vector<std::shared_ptr<UI_Element>>& top_elem,
		std::vector<std::shared_ptr<UI_Element>>& bottom_elem) = 0;
	virtual void unload(void) = 0;
	virtual void update(std::vector<std::shared_ptr<UI_Element>>& top_elem,
		std::vector<std::shared_ptr<UI_Element>>& bottom_elem, u32 key_down) = 0;
	void update_selected(std::shared_ptr<AButton> selected);

protected:
	std::shared_ptr<AButton> m_selected;
};

#endif // !SCENES_HPP
