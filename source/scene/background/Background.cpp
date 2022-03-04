#include "./Background.hpp"
#include "../../UI/Colors.hpp"

void Background::update_top(void) {
	C2D_DrawRectangle(0, 0, 0, 400, 240, colors::background_top, colors::background_top,
		colors::background_middle, colors::background_middle);
}

void Background::update_bottom(void) {
	C2D_DrawRectangle(0, 0, 0, 320, 240, colors::background_middle, colors::background_middle,
		colors::background_bottom, colors::background_bottom);
}
