#include "Game_Art.hpp"
#include "./Colors.hpp"

Game_Art::Game_Art(Vec3 pos, std::string name, std::string image_path) {
	m_pos = pos;
	m_game_name = name;
	C2D_SpriteSheet sheet = C2D_SpriteSheetLoad("romfs:/gfx/game_art.t3x");
	m_image = C2D_SpriteSheetGetImage(sheet, 0);
	C2D_SpriteSheetFree(sheet);
}

void Game_Art::draw_lines(void) {
	C2D_DrawRectSolid(m_pos.x, m_pos.y + 5, m_pos.z, 80, 70, colors::base);
	C2D_DrawRectSolid(m_pos.x + 5, m_pos.y, m_pos.z, 70, 5, colors::base);
	C2D_DrawRectSolid(m_pos.x + 5, m_pos.y + 75, m_pos.z, 70, 5, colors::base);
	C2D_DrawImageAt(m_image, m_pos.x + 5, m_pos.y + 5, m_pos.z + 1, nullptr, 70.0f / 256.0f, 70.0f / 256.0f);
}

void Game_Art::draw_circles(void) {
	C2D_DrawCircleSolid(m_pos.x + 5, m_pos.y + 5, m_pos.z, 5, colors::base);
	C2D_DrawCircleSolid(m_pos.x + 75, m_pos.y + 5, m_pos.z, 5, colors::base);
	C2D_DrawCircleSolid(m_pos.x + 5, m_pos.y + 75, m_pos.z, 5, colors::base);
	C2D_DrawCircleSolid(m_pos.x + 75, m_pos.y + 75, m_pos.z, 5, colors::base);
}
