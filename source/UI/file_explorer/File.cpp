#include "./File.hpp"

File::File(Vec3 pos, std::string text, bool selected, std::function<void(std::string)> press) :
m_text(Text(Vec3(pos.x + 20, pos.y, pos.z), text)),
m_pointer(Vec3(pos.x - 10, pos.y + 10, pos.z)) {
	m_pos = pos;
	m_is_locked = false;
	m_is_selected = selected;
	m_visible = true;
	type = AButton::Type::FILE;
	this->press = press;
}

void File::draw_lines(void) {
	if (!m_visible)
		return;
	u32 color = get_color();
	C2D_DrawRectSolid(m_pos.x + 20, m_pos.y, m_pos.z, 270, 40, color);
	m_text.draw_lines_centered_Y(40);

	if (m_is_selected)
		m_pointer.draw_lines();
}

void File::draw_circles(void) {
	if (!m_visible)
		return;
	u32 color = get_color();
	C2D_DrawCircleSolid(m_pos.x + 20, m_pos.y + 20, m_pos.z, 20, color);

	if (m_is_selected)
		m_pointer.draw_circles();
}

void File::update(std::string text, bool visible) {
	m_visible = visible;
	m_text.update(text);
}
