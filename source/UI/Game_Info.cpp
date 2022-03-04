#include "./Game_Info.hpp"
#include "./Colors.hpp"
#include "./Text.hpp"
#include "../Game/current_game.hpp"
#include "../utils/SpriteSheet.hpp"

Game_Info::Game_Info(C2D_Font font, C2D_SpriteSheet& sheet) {
	const int idx = spritesheet::game_logo.at(game::current()->get_logo());
	m_image = C2D_SpriteSheetGetImage(sheet, idx);
	m_font = font;
}

void Game_Info::draw_lines(void) {
	// Title
	C2D_DrawRectSolid(25, 20, 0, 270, 30, colors::title_background);
	C2D_DrawRectSolid(20, 25, 0, 5, 25, colors::title_background);
	C2D_DrawRectSolid(295, 25, 0, 5, 25, colors::title_background);
	Text(Vec3(20, 20, 0), game::current()->get_name(), m_font, colors::white).draw_lines(Vec2(280, 30));

	// Game logo
	C2D_DrawImageAt(m_image, 30, 50, 0);

	// Box
	C2D_DrawRectSolid(20, 50, 0, 280, 170, colors::game_info_background);
}

void Game_Info::draw_circles(void) {
	// Title
	C2D_DrawCircleSolid(25, 25, 0, 5, colors::title_background);
	C2D_DrawCircleSolid(295, 25, 0, 5, colors::title_background);
}
