#ifndef SCENES_HPP
#define SCENES_HPP

#include <vector>
#include <memory>
#include "../UI/AButton.hpp"
#include <string>

class Scene {
public:
	virtual void load(std::vector<std::shared_ptr<UI_Element>>& top_elem,
		std::vector<std::shared_ptr<UI_Element>>& bottom_elem) = 0;
	virtual void unload(void) = 0;
	virtual void update(std::vector<std::shared_ptr<UI_Element>>& top_elem,
		std::vector<std::shared_ptr<UI_Element>>& bottom_elem, u32 key_down) = 0;
	void update_selected(std::shared_ptr<AButton> selected);
	std::string get_name(void);

protected:
	std::string m_name;
	std::shared_ptr<AButton> m_selected;
	std::shared_ptr<AButton> m_old_selected;
};

#endif // !SCENES_HPP
