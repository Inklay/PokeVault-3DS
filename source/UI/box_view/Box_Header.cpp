#include "./Box_header.hpp"

Box_Header::Box_Header(std::string text, bool is_selected, int x_fix) : 
m_is_selected(is_selected),
m_x_fix(x_fix),
m_box_name(Button(Vec3(120 + m_x_fix, 25, 0), Vec2(80, 20), text)), 
m_left(Text(Vec3(30 + m_x_fix, 20, 0), "<")),
m_right(Text(Vec3(270 + m_x_fix, 20, 0), ">")),
m_l(Text(Vec3(40 + m_x_fix, 20, 0), "")),
m_r(Text(Vec3(260 + m_x_fix, 20, 0), "")) {
}

void Box_Header::draw_lines(void) {
	u32 title_color = m_is_selected ? colors::title_background : colors::title_unselected_background;

	// Box name
	C2D_DrawRectSolid(25 + m_x_fix, 20, 0, 270, 30, title_color);
	C2D_DrawRectSolid(20 + m_x_fix, 25, 0, 5, 25, title_color);
	C2D_DrawRectSolid(295 + m_x_fix, 25, 0, 5, 25, title_color);
	m_box_name.draw_lines();
	m_left.draw_lines_centered_XY(Vec2(20, 30));
	m_right.draw_lines_centered_XY(Vec2(20, 30));

	if (m_is_selected) {
		m_l.draw_lines_centered_XY(Vec2(20, 30));
		m_r.draw_lines_centered_XY(Vec2(20, 30));
	}
}

void Box_Header::draw_circles(void) {
	u32 title_color = m_is_selected ? colors::title_background : colors::title_unselected_background;

	C2D_DrawCircleSolid(25 + m_x_fix, 25, 0, 5, title_color);
	C2D_DrawCircleSolid(295 + m_x_fix, 25, 0, 5, title_color);
	m_box_name.draw_circles();
}

void Box_Header::update(std::string text, bool is_selected) {

}
