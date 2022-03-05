#include "Game_Art.hpp"
#include "../Colors.hpp"
#include "../../utils/SpriteSheet.hpp"

Game_Art::Game_Art(Vec3 pos, std::string image_path, C2D_SpriteSheet& sheet, std::function<void(void)> func, bool is_locked, bool is_selected) :
Button(pos, Vec2(), "", func, is_locked, is_selected) {
	m_pos = pos;
	m_pointer_dir = 1;
	m_pointer_off = 0;
	m_image.init(spritesheet::game_art.at(image_path), sheet);
}

void Game_Art::draw_lines(void) {
	const u32 color = get_color();
	C2D_DrawRectSolid(m_pos.x, m_pos.y + 10, m_pos.z, 70, 50, color);
	C2D_DrawRectSolid(m_pos.x + 10, m_pos.y, m_pos.z, 50, 10, color);
	C2D_DrawRectSolid(m_pos.x + 10, m_pos.y + 60, m_pos.z, 50, 10, color);
	
	if (m_is_selected) {
		if (m_pointer_off >= 0 || m_pointer_off <= -2)
			m_pointer_dir *= -1;
		m_pointer_off += 0.085f * m_pointer_dir;
		m_pointer.draw_lines(Vec3(m_pos.x - 10 + m_pointer_off, m_pos.y + 26, m_pos.z));
	}
}

void Game_Art::draw_circles(void) {
	const u32 color = get_color();
	C2D_DrawCircleSolid(m_pos.x + 10, m_pos.y + 10, m_pos.z, 10, color);
	C2D_DrawCircleSolid(m_pos.x + 60, m_pos.y + 10, m_pos.z, 10, color);
	C2D_DrawCircleSolid(m_pos.x + 10, m_pos.y + 60, m_pos.z, 10, color);
	C2D_DrawCircleSolid(m_pos.x + 60, m_pos.y + 60, m_pos.z, 10, color);
	m_image.draw_lines(Vec3(m_pos.x + 5, m_pos.y + 5, m_pos.z), Vec2(60.0f / 128.0f, 60.0f / 128.0f));

	if (m_is_selected)
		m_pointer.draw_circles(Vec3(m_pos.x - 10 + m_pointer_off, m_pos.y + 27, m_pos.z));
}
