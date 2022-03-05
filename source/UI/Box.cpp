#include "./Box.hpp"
#include <citro2d.h>
#include "./Colors.hpp"

Box::Box(Vec3 pos, Vec2 size, std::string text, u32 color, bool visible) :
m_text(Text(pos, text)) {
	m_pos = pos;
	m_size = size;
	m_visible = visible;
	m_color = color;
}

void Box::draw_lines(void) {
	if (!m_visible)
		return;
	C2D_DrawRectSolid(m_pos.x + 5, m_pos.y, m_pos.z, m_size.x - 10, m_size.y, m_color);
	C2D_DrawRectSolid(m_pos.x, m_pos.y + 5, m_pos.z, 5, m_size.y - 10, m_color);
	C2D_DrawRectSolid(m_pos.x + m_size.x - 5, m_pos.y + 5, m_pos.z, 5, m_size.y - 10, m_color);
	m_text.draw_lines_centered_XY(m_size);
}

void Box::draw_circles(void) {
	if (!m_visible)
		return;
	C2D_DrawCircleSolid(m_pos.x + 5, m_pos.y + 5, m_pos.z, 5, m_color);
	C2D_DrawCircleSolid(m_pos.x + 5, m_pos.y + m_size.y - 5, m_pos.z, 5, m_color);
	C2D_DrawCircleSolid(m_pos.x + m_size.x - 5, m_pos.y + 5, m_pos.z, 5, m_color);
	C2D_DrawCircleSolid(m_pos.x + m_size.x - 5, m_pos.y + m_size.y - 5, m_pos.z, 5, m_color);
}

void Box::update(bool visible) {
	m_visible = visible;
}
