#include "Game_Art.hpp"
#include "../utils/SpriteSheet.hpp"
#include "./Colors.hpp"

Game_Art::Game_Art(Vec3 pos, std::string image_path, C2D_SpriteSheet& sheet, bool is_locked, bool is_selected) :
Button(pos, Vec2(), "", is_locked, is_selected) {
	m_pos = pos;
	const int idx = spritesheet::game_art.at(image_path);
	m_image = C2D_SpriteSheetGetImage(sheet, idx);
}

void Game_Art::draw_lines(void) {
	const u32 color = get_color();
	C2D_DrawRectSolid(m_pos.x, m_pos.y + 10, m_pos.z, 70, 50, color);
	C2D_DrawRectSolid(m_pos.x + 10, m_pos.y, m_pos.z, 50, 10, color);
	C2D_DrawRectSolid(m_pos.x + 10, m_pos.y + 60, m_pos.z, 50, 10, color);
	
}

void Game_Art::draw_circles(void) {
	const u32 color = get_color();
	C2D_DrawCircleSolid(m_pos.x + 10, m_pos.y + 10, m_pos.z, 10, color);
	C2D_DrawCircleSolid(m_pos.x + 60, m_pos.y + 10, m_pos.z, 10, color);
	C2D_DrawCircleSolid(m_pos.x + 10, m_pos.y + 60, m_pos.z, 10, color);
	C2D_DrawCircleSolid(m_pos.x + 60, m_pos.y + 60, m_pos.z, 10, color);
	C2D_DrawImageAt(m_image, m_pos.x + 5, m_pos.y + 5, m_pos.z + 1, nullptr, 60.0F / 128.0f, 60.0F / 128.0f);
}
