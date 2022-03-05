#include "./Text.hpp"

Text::Text(Vec3 pos, std::string text, u32 color) {
	m_pos = pos;
	m_text_buf = C2D_TextBufNew(64);
	m_color = color;
	C2D_TextParse(&m_text, m_text_buf, text.c_str());
	C2D_TextOptimize(&m_text);
}

Text::~Text(void) {
	C2D_TextBufDelete(m_text_buf);
}

void Text::draw_lines(void) {
	C2D_DrawText(&m_text, C2D_WithColor, m_pos.x, m_pos.y, m_pos.z, 0.5f, 0.5f, m_color);
}

void Text::draw_lines_centered_XY(Vec2 size, float font_size) {
	float height;
	float width;
	C2D_TextGetDimensions(&m_text, font_size, font_size, &width, &height);
	int x = size.x / 2 - width / 2 + m_pos.x;
	int y = size.y / 2 - height / 2 + m_pos.y;
	C2D_DrawText(&m_text, C2D_WithColor, x, y, m_pos.z + 1, font_size, font_size, m_color);
}

void Text::draw_lines_centered_Y(int y, float font_size) {
	float height;
	C2D_TextGetDimensions(&m_text, font_size, font_size, 0, &height);
	int text_y = y / 2 - height / 2 + m_pos.y;
	C2D_DrawText(&m_text, C2D_WithColor, m_pos.x, text_y, m_pos.z + 1, font_size, font_size, m_color);
}

void Text::draw_lines_centered_X(int x, float font_size) {
	float width;
	C2D_TextGetDimensions(&m_text, font_size, font_size, &width, 0);
	int text_x = x / 2 - width / 2 + m_pos.x;
	C2D_DrawText(&m_text, C2D_WithColor, text_x, m_pos.y, m_pos.z + 1, font_size, font_size, m_color);
}

void Text::update(std::string text) {
	C2D_TextBufClear(m_text_buf);
	C2D_TextParse(&m_text, m_text_buf, text.c_str());
	C2D_TextOptimize(&m_text);
}

void Text::draw_circles(void) {}
