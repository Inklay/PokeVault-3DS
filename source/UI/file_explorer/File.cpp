#include "File.hpp"
#include "../Text.hpp"

File::File(Vec3 pos, std::string text, bool selected) {
	m_pos = pos;
	m_is_locked = false;
	m_is_selected = selected;
}

void File::draw_lines(void) {
	u32 color = get_color();
	C2D_DrawRectSolid(m_pos.x + 20, m_pos.y, m_pos.z, 270, 40, color);
}

void File::draw_circles(void) {
	u32 color = get_color();
	C2D_DrawCircleSolid(m_pos.x + 20, m_pos.y + 20, m_pos.z, 20, color);
}
