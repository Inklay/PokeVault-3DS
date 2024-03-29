#include "./ArrowPointer.hpp"
#include "./Colors.hpp"
#include <citro2d.h>

ArrowPointer::ArrowPointer(Vec3 pos) {
	m_off = 0;
	m_dir = 1;
	m_pos = pos;
}

void ArrowPointer::DrawLines(void) {
	if (m_off >= 0 || m_off <= -2)
		m_dir *= -1;
	m_off += 0.085f * m_dir;

	float x = m_pos.x + m_off;

	C2D_DrawLine(x, m_pos.y, colors::white,
		x, m_pos.y + 20, colors::white, 6, m_pos.z);
	C2D_DrawLine(x, m_pos.y + 20, colors::white,
		x + 10, m_pos.y + 10, colors::white, 6, m_pos.z);
	C2D_DrawLine(x + 10, m_pos.y + 10, colors::white,
		x, m_pos.y, colors::white, 6, m_pos.z);

	C2D_DrawTriangle(x, m_pos.y, colors::arrow_pointer,
		x, m_pos.y + 20, colors::arrow_pointer,
		x + 10, m_pos.y + 10, colors::arrow_pointer, m_pos.z + 0.1f);
}

void ArrowPointer::DrawCircles(void) {
	float x = m_pos.x + m_off;

	C2D_DrawCircleSolid(x, m_pos.y, m_pos.z, 3, colors::white);
	C2D_DrawCircleSolid(x, m_pos.y + 20, m_pos.z, 3, colors::white);
	C2D_DrawCircleSolid(x + 10, m_pos.y + 10, m_pos.z, 3, colors::white);
}
