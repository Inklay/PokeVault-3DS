#ifndef BOXVIEW
#define BOXVIEW

#include "./Scene.hpp"
#include "../UI/BoxView/Box.hpp"

class BoxView : public Scene {
public:
	BoxView(App* app);
	void DrawTop();
	void DrawBottom();
	void Update(u32 key_down);

private:
	u8 m_current_box;
	Box m_box_bottom;
	Box m_box_top;
	bool m_viewing_top;
};

#endif // !BOXVIEW
