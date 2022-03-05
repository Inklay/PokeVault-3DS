#include "./Button.hpp"
#include "./Colors.hpp"
#include <3ds.h>

Button::Button(Vec3 pos, Vec2 size, std::string text, std::function<void(void)> func, bool locked, bool selected) :
m_text(Text(pos, text)) {
	m_is_locked = locked;
	m_is_selected = selected;
	m_pos = pos;
	m_size = size;
	m_func = func;
	type = AButton::Type::BUTTON;
}

void Button::draw_lines(void) {
	C2D_DrawRectSolid(m_pos.x + m_size.y / 2, m_pos.y, m_pos.z, m_size.x - m_size.y, m_size.y, get_color());
	m_text.draw_lines_centered_XY(m_size);
}

void Button::draw_circles(void) {
	const int radius = m_size.y / 2;
	C2D_DrawCircleSolid(m_pos.x + radius, m_pos.y + radius, m_pos.z, radius, get_color());
	C2D_DrawCircleSolid(m_size.x - radius, m_pos.y + radius, m_pos.z, radius, get_color());
}

void Button::pressed(void) {
	m_func();
}
