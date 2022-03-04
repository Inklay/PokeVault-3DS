#include "./Background.hpp"
#include "./Colors.hpp"

Background::Background(Screen screen) {
	m_screen = screen;
}

void Background::draw_lines(void) {
	if (m_screen == Screen::TOP)
		C2D_DrawRectangle(0, 0, 0, 400, 240, colors::background_top, colors::background_top,
			colors::background_middle, colors::background_middle);
	else
		C2D_DrawRectangle(0, 0, 0, 320, 240, colors::background_middle, colors::background_middle,
			colors::background_bottom, colors::background_bottom);
}
