#include "GameArt.hpp"
#include "../Colors.hpp"
#include "../../utils/SpriteSheet.hpp"

GameArt::GameArt(Vec3 pos, std::string image_path, C2D_SpriteSheet& sheet, bool is_locked, bool is_selected) :
m_pointer(Vec3(pos.x - 10, pos.y + 27, pos.z)) {
	m_is_selected = is_selected;
	m_is_locked = is_locked;
	m_pos = pos;
	type = UIElement::Type::GAME_ART;
	m_image.Init(spritesheet::game_art.at(image_path), sheet);
}

void GameArt::DrawLines() {
	const u32 color = GetColor();
	C2D_DrawRectSolid(m_pos.x, m_pos.y + 10, m_pos.z, 70, 50, color);
	C2D_DrawRectSolid(m_pos.x + 10, m_pos.y, m_pos.z, 50, 10, color);
	C2D_DrawRectSolid(m_pos.x + 10, m_pos.y + 60, m_pos.z, 50, 10, color);
	
	if (m_is_selected)
		m_pointer.DrawLines();
}

void GameArt::DrawCircles() {
	const u32 color = GetColor();
	C2D_DrawCircleSolid(m_pos.x + 10, m_pos.y + 10, m_pos.z, 10, color);
	C2D_DrawCircleSolid(m_pos.x + 60, m_pos.y + 10, m_pos.z, 10, color);
	C2D_DrawCircleSolid(m_pos.x + 10, m_pos.y + 60, m_pos.z, 10, color);
	C2D_DrawCircleSolid(m_pos.x + 60, m_pos.y + 60, m_pos.z, 10, color);
	m_image.DrawLines(Vec3(m_pos.x + 5, m_pos.y + 5, m_pos.z), Vec2(60.0f / 128.0f, 60.0f / 128.0f));

	if (m_is_selected)
		m_pointer.DrawCircles();
}
