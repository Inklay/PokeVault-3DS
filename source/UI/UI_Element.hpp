#ifndef UI_ELEMENT
#define UI_ELEMENT

#include "../utils/Vec3.hpp"

class UI_Element {
public:
	virtual void draw_lines(void) = 0;
	virtual void draw_circles(void) = 0;

protected:
	Vec3 m_pos;
};

#endif // !UI_ELEMENT
