#include "./Header.hpp"
#include "./Colors.hpp"

Header::Header(std::string text) :
m_text(Text(Vec3(), text)) {}

void Header::draw_lines(void) {
	C2D_DrawRectangle(0, 0, 0, 400, 30, colors::header_top, colors::header_top, colors::header_bottom, colors::header_bottom);
	m_text.draw_lines(Vec2(400, 30));
}

void Header::draw_circles(void)  {}
