#include "./Game_Info.hpp"
#include "../Colors.hpp"
#include "../Text.hpp"
#include "../../Game/current_game.hpp"
#include "../../utils/SpriteSheet.hpp"

Game_Info::Game_Info(C2D_SpriteSheet& sheet) {
	m_image.init(spritesheet::game_logo.at(game::current()->get_logo()), sheet);
}

void Game_Info::draw_lines(void) {
	// Title
	C2D_DrawRectSolid(25, 20, 0, 270, 30, colors::title_background);
	C2D_DrawRectSolid(20, 25, 0, 5, 25, colors::title_background);
	C2D_DrawRectSolid(295, 25, 0, 5, 25, colors::title_background);
	Text(Vec3(20, 20, 0), game::current()->get_name(), colors::white).draw_lines(Vec2(280, 30));

	// Game logo
	m_image.draw_lines(Vec3(30, 50, 0), Vec2(1, 1));

	// Box
	C2D_DrawRectSolid(20, 50, 0, 280, 170, colors::game_info_background);

	if (game::current()->has_save())
		draw_info();
	else
		draw_no_save_lines();
}

void Game_Info::draw_info(void) {

}

void Game_Info::draw_no_save_lines(void) {
	C2D_DrawRectSolid(165, 60, 0, 120, 120, colors::info_background);
	C2D_DrawRectSolid(160, 65, 0, 5, 110, colors::info_background);
	C2D_DrawRectSolid(285, 65, 0, 5, 110, colors::info_background);
	Text(Vec3(160, 60, 0), "No save data\nfound, press \nto load one\nor insert\na cartridge").draw_lines(Vec2(130, 120));
}


void Game_Info::draw_no_save_circles(void) {
	C2D_DrawCircleSolid(165, 65, 0, 5, colors::info_background);
	C2D_DrawCircleSolid(165, 175, 0, 5, colors::info_background);
	C2D_DrawCircleSolid(285, 65, 0, 5, colors::info_background);
	C2D_DrawCircleSolid(285, 175, 0, 5, colors::info_background);
}

void Game_Info::draw_circles(void) {
	// Title
	C2D_DrawCircleSolid(25, 25, 0, 5, colors::title_background);
	C2D_DrawCircleSolid(295, 25, 0, 5, colors::title_background);

	if (!game::current()->has_save())
		draw_no_save_circles();
}
