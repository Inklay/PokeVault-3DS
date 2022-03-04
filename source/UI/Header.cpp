#include "./Header.hpp"
#include "./Colors.hpp"

Header::Header(std::string text, C2D_Font font) :
m_text(Text(Vec3(), text, font)) {}

void Header::draw_lines(void) {
	C2D_DrawRectangle(0, 0, 0, 400, 30, colors::header_top, colors::header_top, colors::header_bottom, colors::header_bottom);
	C2D_DrawRectangle(0, 30, 0, 400, 20, colors::header_shadow_top, colors::header_shadow_top,
		colors::header_shadow_bottom, colors::header_shadow_bottom);
	m_text.draw_lines(Vec2(400, 30));
}
