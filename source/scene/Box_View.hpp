#ifndef BOX_VIEW
#define BOX_VIEW

#include "./Scene.hpp"
#include "../core/source/Save/Box/Base_Box.hpp"

class Box_View : public Scene {
public:
	Box_View(void);
	void load(std::vector<std::shared_ptr<UI_Element>>& top_elem,
		std::vector<std::shared_ptr<UI_Element>>& bottom_elem);
	void unload(void);
	void update(std::vector<std::shared_ptr<UI_Element>>& top_elem,
		std::vector<std::shared_ptr<UI_Element>>& bottom_elem, u32 key_down);

private:
	Base_Box& m_box;
};

#endif // !BOX_VIEW
