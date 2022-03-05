#include "./Footer.hpp"
#include "./Colors.hpp"

Footer::Footer(std::string text, gfxScreen_t screen, Text::center_mode mode) :
m_text(Text(Vec3(5, 220, 0), text)) {
	m_screen = screen;
	m_mode = mode;
}

void Footer::draw_lines(void) {
	int w;
	if (m_screen == GFX_BOTTOM)
		w = 320;
	else
		w = 400;
	C2D_DrawRectangle(0, 220, 0, w, 20, colors::header_top, colors::header_top, colors::header_bottom, colors::header_bottom);
	if (m_mode == Text::center_mode::BOTH)
		m_text.draw_lines_centered_XY(Vec2(w, 20));
	else if (m_mode == Text::center_mode::X)
		m_text.draw_lines_centered_X(w);
	else
		m_text.draw_lines_centered_Y(20);
}

void Footer::update(std::string text) {
	m_text.update(text);
}
