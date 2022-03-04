#include "Game_Art.hpp"
#include "../utils/SpriteSheet.hpp"
#include <iostream>
#include "./Colors.hpp"

Game_Art::Game_Art(Vec3 pos, std::string name, std::string image_path, C2D_SpriteSheet& sheet) :
Button(pos, Vec2(), "", isCompatible(name), false) {
	m_pos = pos;
	m_game_name = name;
	const int idx = spritesheet::game_art.at(image_path);
	m_image = C2D_SpriteSheetGetImage(sheet, idx);
}

void Game_Art::draw_lines(void) {
	const u32 color = get_color();
	C2D_DrawRectSolid(m_pos.x, m_pos.y + 10, m_pos.z, 60, 40, color);
	C2D_DrawRectSolid(m_pos.x + 10, m_pos.y, m_pos.z, 40, 10, color);
	C2D_DrawRectSolid(m_pos.x + 10, m_pos.y + 50, m_pos.z, 40, 10, color);
	
}

void Game_Art::draw_circles(void) {
	const u32 color = get_color();
	C2D_DrawCircleSolid(m_pos.x + 10, m_pos.y + 10, m_pos.z, 10, color);
	C2D_DrawCircleSolid(m_pos.x + 50, m_pos.y + 10, m_pos.z, 10, color);
	C2D_DrawCircleSolid(m_pos.x + 10, m_pos.y + 50, m_pos.z, 10, color);
	C2D_DrawCircleSolid(m_pos.x + 50, m_pos.y + 50, m_pos.z, 10, color);
	C2D_DrawImageAt(m_image, m_pos.x + 5, m_pos.y + 5, m_pos.z + 1, nullptr, 50.0F / 128.0f, 50.0F / 128.0f);
}

bool Game_Art::isCompatible(std::string name) {
	return name != "Platinum";
}