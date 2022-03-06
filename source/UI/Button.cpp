#include "./Button.hpp"
#include "./Colors.hpp"
#include <3ds.h>

Button::Button(Vec3 pos, Vec2 size, std::string text, bool locked, bool selected) :
m_text(Text(Vec3(pos.x, pos.y, 0), text)),
m_pointer(Arrow_Pointer(Vec3(pos.x - 10, pos.y, pos.z + 0.1f))) {
	m_is_locked = locked;
	m_is_selected = selected;
	m_pos = pos;
	m_size = size;
	type = UI_Element::Type::BUTTON;
}

void Button::draw_lines(void) {
	C2D_DrawRectSolid(m_pos.x + m_size.y / 2, m_pos.y, m_pos.z, m_size.x - m_size.y, m_size.y, get_color());
	m_text.draw_lines_centered_XY(m_size);

	if (m_is_selected)
		m_pointer.draw_lines();
}

void Button::draw_circles(void) {
	const int radius = m_size.y / 2;
	C2D_DrawCircleSolid(m_pos.x + radius, m_pos.y + radius, m_pos.z, radius, get_color());
	C2D_DrawCircleSolid(m_pos.x + m_size.x - radius, m_pos.y + radius, m_pos.z, radius, get_color());

	if (m_is_selected)
		m_pointer.draw_circles();
}
