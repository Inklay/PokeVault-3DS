#include "./File.hpp"

File::File(Vec3 pos, std::string text, bool selected) :
m_text(Text(Vec3(pos.x + 20, pos.y, pos.z - 0.9f), text)),
m_pointer(Vec3(pos.x - 10, pos.y + 10, pos.z)) {
	m_pos = pos;
	m_is_locked = false;
	m_is_selected = selected;
	m_visible = true;
	type = UIElement::Type::FILE;
}

void File::DrawLines(void) {
	if (!m_visible) {
		return;
	}
	u32 color = GetColor();
	C2D_DrawRectSolid(m_pos.x + 20, m_pos.y, m_pos.z, 270, 40, color);
	m_text.DrawLinesCenteredY(40);

	if (m_is_selected)
		m_pointer.DrawLines();
}

void File::DrawCircles(void) {
	if (!m_visible) {
		return;
	}
	u32 color = GetColor();
	C2D_DrawCircleSolid(m_pos.x + 20, m_pos.y + 20, m_pos.z, 20, color);

	if (m_is_selected)
		m_pointer.DrawCircles();
}

void File::Update(std::string text, bool visible) {
	m_visible = visible;
	m_text.Update(text);
}
