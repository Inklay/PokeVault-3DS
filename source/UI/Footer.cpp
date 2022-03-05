#include "./Footer.hpp"
#include "./Colors.hpp"

Footer::Footer(std::string text) :
	m_text(Text(Vec3(5, 220, 0), text)) {}

void Footer::draw_lines(void) {
	C2D_DrawRectangle(0, 220, 0, 320, 20, colors::header_top, colors::header_top, colors::header_bottom, colors::header_bottom);
	m_text.draw_lines_centered_Y(20);
}
