#include "./Footer.hpp"
#include "./Colors.hpp"

Footer::Footer(std::string text, gfxScreen_t screen, Text::CenterMode mode) :
m_text(Text(Vec3(5, 220, 0), text)) {
	m_screen = screen;
	m_mode = mode;
}

void Footer::DrawLines() {
	int w;
	if (m_screen == GFX_BOTTOM)
		w = 320;
	else
		w = 400;
	C2D_DrawRectangle(0, 220, 0, w, 20, colors::header_top, colors::header_top, colors::header_bottom, colors::header_bottom);
	if (m_mode == Text::CenterMode::BOTH)
		m_text.DrawLinesCenteredXY(Vec2(w, 20));
	else if (m_mode == Text::CenterMode::X)
		m_text.DrawLinesCenteredX(w);
	else
		m_text.DrawLinesCenteredY(20);
}

void Footer::Update(std::string text) {
	m_text.Update(text);
}
