#include "./BackgroundSquare.hpp"

BackgroundSquare::BackgroundSquare(Vec3 pos, float speed, int size, u32 color) {
	m_pos = pos;
	m_speed = speed;
	m_size = size;
	m_color = color;
	m_done = false;
}

void BackgroundSquare::DrawTop() {
	if (m_pos.y > 240)
		return;
	if (m_pos.y + m_size < 0)
		m_done = true;
	C2D_DrawRectSolid(m_pos.x, m_pos.y, m_pos.z, m_size, m_size, m_color);
}

void BackgroundSquare::DrawBottom() {
	m_pos.y -= m_speed;
	if (m_pos.y + m_size < 240)
		return;
	C2D_DrawRectSolid(m_pos.x - 40, m_pos.y - 240, m_pos.z, m_size, m_size, m_color);
}

bool BackgroundSquare::IsDone() {
	return m_done;
}
