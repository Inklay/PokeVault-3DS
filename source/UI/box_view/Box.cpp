#include "./Box.hpp"
#include "../Colors.hpp"

Box::Box(bool selected, Base_Box& box, gfxScreen_t screen) :
m_box(box),
m_is_selected(selected),
m_x_fix((screen == GFX_BOTTOM) ? 0 : 40),
m_header(Box_Header(box.get_name(), selected, m_x_fix)) {
}

void Box::draw_lines(void) {
	u32 title_color = m_is_selected ? colors::title_background : colors::title_unselected_background;
	u32 box_color = m_is_selected ? colors::white : colors::box_unselected_background;

	// Box name
	m_header.draw_lines();

	// Box body
	C2D_DrawRectSolid(20 + m_x_fix, 50, 0, 280, 170, box_color);

	if (m_is_selected) {
		C2D_DrawLine(21 + m_x_fix, 50, title_color, 21 + m_x_fix, 220, title_color, 2, 0);
		C2D_DrawLine(299 + m_x_fix, 50, title_color, 299 + m_x_fix, 220, title_color, 2, 0);
		C2D_DrawLine(20 + m_x_fix, 219, title_color, 299 + m_x_fix, 219, title_color, 2, 0);
	}
}

void Box::draw_circles(void) {
	m_header.draw_circles();
}

void Box::update(bool selected, Base_Box& box) {
	m_is_selected = selected;
	m_box = box;
}
