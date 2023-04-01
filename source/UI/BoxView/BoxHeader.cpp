#include "./BoxHeader.hpp"

BoxHeader::BoxHeader(std::string text, bool is_selected, int x_fix) :
m_is_selected(is_selected),
m_x_fix(x_fix),
m_box_name(Button(Vec3(120 + m_x_fix, 10, 0), Vec2(80, 20), text)), 
m_left(Text(Vec3(35 + m_x_fix, 5, 0), "<")),
m_right(Text(Vec3(270 + m_x_fix, 5, 0), ">")),
m_l(Text(Vec3(45 + m_x_fix, 5, 0), "")),
m_r(Text(Vec3(260 + m_x_fix, 5, 0), "")) {
}

void BoxHeader::DrawLines(void) {
	u32 title_color = m_is_selected ? colors::title_background : colors::title_unselected_background;

	// Box name
	C2D_DrawRectSolid(35 + m_x_fix, 5, 0, 250, 30, title_color);
	C2D_DrawRectSolid(30 + m_x_fix, 10, 0, 5, 25, title_color);
	C2D_DrawRectSolid(285 + m_x_fix, 10, 0, 5, 25, title_color);
	m_box_name.DrawLines();
	m_left.DrawLinesCenteredXY(Vec2(20, 30));
	m_right.DrawLinesCenteredXY(Vec2(20, 30));

	if (m_is_selected) {
		m_l.DrawLinesCenteredXY(Vec2(20, 30));
		m_r.DrawLinesCenteredXY(Vec2(20, 30));
	}
}

void BoxHeader::DrawCircles(void) {
	u32 title_color = m_is_selected ? colors::title_background : colors::title_unselected_background;

	C2D_DrawCircleSolid(35 + m_x_fix, 10, 0, 5, title_color);
	C2D_DrawCircleSolid(285 + m_x_fix, 10, 0, 5, title_color);
	m_box_name.DrawCircles();
}

void BoxHeader::Update(std::string text, bool is_selected, bool is_name_selected) {
	m_is_selected = is_selected;
	m_box_name.Update(text, is_name_selected, false);
}
