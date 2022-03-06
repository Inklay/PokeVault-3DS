#include "./Game_Info.hpp"
#include "../Colors.hpp"
#include "../Text.hpp"
#include "../../Game/current_game.hpp"
#include "../../utils/SpriteSheet.hpp"

Game_Info::Game_Info(C2D_SpriteSheet& sheet) :
m_game_name(Text(Vec3(20, 20, -0.9f), game::current()->get_name(), colors::white)),
m_name_label(Text(Vec3(165, 90, -0.9f), "Name", colors::white)),
m_name_value(Text(Vec3(235, 90, -0.9f), "")),
m_tid_label(Text(Vec3(165, 112, -0.9f), "ID Number", colors::white)),
m_tid_value(Text(Vec3(235, 112, -0.9f), "")),
m_time_played_label(Text(Vec3(165, 134, -0.9f), "Time played", colors::white)),
m_time_played_value(Text(Vec3(235, 134, -0.9f), "")),
m_no_save(Text(Vec3(160, 60, -0.9f), "No save data\nfound, press \nto load one\nor insert\na cartridge")){
	m_image.init(spritesheet::game_logo.at(game::current()->get_logo()), sheet);
	if (game::current()->has_save()) {
		m_name_value.update(game::current()->save->get_username());
		m_tid_value.update(std::to_string(game::current()->save->get_trainer_id()));
		m_time_played_value.update(game::current()->save->get_game_time());
	}
}

void Game_Info::draw_lines(void) {
	// Title
	C2D_DrawRectSolid(25, 20, 0, 270, 30, colors::title_background);
	C2D_DrawRectSolid(20, 25, 0, 5, 25, colors::title_background);
	C2D_DrawRectSolid(295, 25, 0, 5, 25, colors::title_background);
	m_game_name.draw_lines_centered_XY(Vec2(280, 30));

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
	C2D_DrawRectSolid(160, 90, 0, 70, 20, colors::title_background);
	C2D_DrawRectSolid(230, 90, 0, 60, 20, colors::white);
	m_name_label.draw_lines_centered_XY(Vec2(60, 20), 0.4f);
	m_name_value.draw_lines_centered_Y(20, 0.4f);

	C2D_DrawRectSolid(160, 112, 0, 70, 20, colors::title_background);
	C2D_DrawRectSolid(230, 112, 0, 60, 20, colors::white);
	m_tid_label.draw_lines_centered_XY(Vec2(60, 20), 0.4f);
	m_tid_value.draw_lines_centered_Y(20, 0.4f);

	C2D_DrawRectSolid(160, 134, 0, 70, 20, colors::title_background);
	C2D_DrawRectSolid(230, 134, 0, 60, 20, colors::white);
	m_time_played_label.draw_lines_centered_XY(Vec2(60, 20), 0.4f);
	m_time_played_value.draw_lines_centered_Y(20, 0.4f);
}

void Game_Info::draw_no_save_lines(void) {
	C2D_DrawRectSolid(165, 60, 0, 120, 120, colors::info_background);
	C2D_DrawRectSolid(160, 65, 0, 5, 110, colors::info_background);
	C2D_DrawRectSolid(285, 65, 0, 5, 110, colors::info_background);
	m_no_save.draw_lines_centered_XY(Vec2(130, 120));
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
