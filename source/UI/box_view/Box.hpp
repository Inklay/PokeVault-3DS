#ifndef BOX_HPP
#define BOX_HPP

#include "../UI_Element.hpp"
#include "../Button.hpp"
#include "../../core/source/Save/Box/Base_Box.hpp"
#include <3ds.h>
#include "./Box_header.hpp"

class Box : public UI_Element {
public:
	Box(bool selected, Base_Box& box, gfxScreen_t screen);
	void draw_lines(void);
	void draw_circles(void);
	void update(bool selected, Base_Box& box);

private:
	Base_Box& m_box;
	bool m_is_selected;
	int m_x_fix;
	Box_Header m_header;
};

#endif // !BOX_HPP
