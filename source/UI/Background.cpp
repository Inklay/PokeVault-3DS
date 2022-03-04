#include "./Background.hpp"
#include "./Colors.hpp"

Background::Background(Screen screen) {
	m_screen = screen;
}

void Background::draw_lines(void) {
	int w;

	if (m_screen == Screen::TOP)
		w = 400;
	else
		w = 320;
	C2D_DrawRectangle(0, 0, 0, w, 240, colors::background_top, colors::background_top,
		colors::background_bottom, colors::background_bottom);
}
