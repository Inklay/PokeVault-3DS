#include "./Text.hpp"

Text::Text(Vec3 pos, std::string text) {
	m_pos = pos;
	m_text_buf = C2D_TextBufNew(64);
	C2D_TextParse(&m_text, m_text_buf, text.c_str());
	C2D_TextOptimize(&m_text);
}

Text::~Text(void) {
	C2D_TextBufDelete(m_text_buf);
}

void Text::draw_lines(void) {
	C2D_DrawText(&m_text, 0, m_pos.x, m_pos.y, m_pos.z, 0.5f, 0.5f);
}

void Text::draw_lines(Vec2 size) {
	float height;
	float width;
	C2D_TextGetDimensions(&m_text, 0.5f, 0.5f, &width, &height);
	int x = size.x / 2 - width / 2 + m_pos.x;
	int y = size.y / 2 - height / 2 + m_pos.y;
	C2D_DrawText(&m_text, 0, x, y, m_pos.z + 1, 0.5f, 0.5f);
}

void Text::draw_circles(void) {}
