#include "./TextBox.hpp"
#include <citro2d.h>
#include "./Colors.hpp"

TextBox::TextBox(Vec3 pos, Vec2 size, std::string text, u32 color, bool visible) :
m_text(Text(pos, text)) {
	m_pos = pos;
	m_size = size;
	m_visible = visible;
	m_color = color;
}

void TextBox::DrawLines(void) {
	if (!m_visible) {
		return;
	}
	C2D_DrawRectSolid(m_pos.x + 5, m_pos.y, m_pos.z, m_size.x - 10, m_size.y, m_color);
	C2D_DrawRectSolid(m_pos.x, m_pos.y + 5, m_pos.z, 5, m_size.y - 10, m_color);
	C2D_DrawRectSolid(m_pos.x + m_size.x - 5, m_pos.y + 5, m_pos.z, 5, m_size.y - 10, m_color);
	m_text.DrawLinesCenteredXY(m_size);
}

void TextBox::DrawCircles(void) {
	if (!m_visible) {
		return;
	}
	C2D_DrawCircleSolid(m_pos.x + 5, m_pos.y + 5, m_pos.z, 5, m_color);
	C2D_DrawCircleSolid(m_pos.x + 5, m_pos.y + m_size.y - 5, m_pos.z, 5, m_color);
	C2D_DrawCircleSolid(m_pos.x + m_size.x - 5, m_pos.y + 5, m_pos.z, 5, m_color);
	C2D_DrawCircleSolid(m_pos.x + m_size.x - 5, m_pos.y + m_size.y - 5, m_pos.z, 5, m_color);
}

void TextBox::Update(bool visible) {
	m_visible = visible;
}
