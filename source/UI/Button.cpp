#include "./Button.hpp"

Button::Button(Vec3 pos, Vec3 size, std::string text, bool locked, bool selected) {
	m_is_locked = locked;
	m_is_selected = selected;
	m_text = text;
	m_pos = pos;
	m_size = size;
}

void Button::draw_lines(void) {
	C2D_DrawRectSolid(m_pos.x + m_size.y / 2, m_pos.y, m_pos.z, m_size.x - m_size.y, m_size.y, m_default_color);
}

void Button::draw_circles(void) {
	const int radius = m_size.y / 2;
	C2D_DrawCircleSolid(m_pos.x + radius, m_pos.y + radius, m_pos.z, radius, m_default_color);
	C2D_DrawCircleSolid(m_size.x - radius, m_pos.y + radius, m_pos.z, radius, m_default_color);
}
