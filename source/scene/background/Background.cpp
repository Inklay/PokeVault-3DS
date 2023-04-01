#include "./Background.hpp"
#include "../../UI/Colors.hpp"
#include <cstdlib>
#include <algorithm>

Background::Background() :
m_colors({ C2D_Color32(0xD3, 0xED, 0xAF, 0xAA),
		   C2D_Color32(0x76, 0x85, 0x61, 0x40),
		   C2D_Color32(0xDE, 0xE6, 0xA3, 0x80),
		   C2D_Color32(0x56, 0x78, 0x66, 0x60),
		   C2D_Color32(0x8F, 0xF7, 0xC8, 0x80),
		   C2D_Color32(0x7C, 0xD8, 0x92, 0xDD),
	}) {
}

void Background::DrawTop() {
	C2D_DrawRectangle(0, 0, 0, 400, 240, colors::background_top, colors::background_top,
		colors::background_middle, colors::background_middle);
	for (auto& s : m_squares)
		s.DrawTop();
}

void Background::DrawBottom() {
	C2D_DrawRectangle(0, 0, 0, 320, 240, colors::background_middle, colors::background_middle,
		colors::background_bottom, colors::background_bottom);
	for (size_t i = 0; i < m_squares.size(); i++) {
		m_squares.at(i).DrawBottom();
		if (m_squares.at(i).IsDone())
			m_squares.erase(m_squares.begin() + i);
	}
	if (m_squares.size() < 6) {
		int x = rand() % 400;
		int size = rand() % 80 + 20;
		float speed = (float)(rand() % 100) / 200.0f + 0.2f;
		u32 color = m_colors[rand() % 6];
		m_squares.emplace_back(BackgroundSquare(Vec3(x, 480.0f, 0), speed, size, color));
	}
}
