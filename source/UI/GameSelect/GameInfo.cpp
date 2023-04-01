#include "./GameInfo.hpp"
#include "../Colors.hpp"
#include "../Text.hpp"
#include "../../utils/SpriteSheet.hpp"

GameInfo::GameInfo(C2D_SpriteSheet& sheet, Game* game) :
	m_game(game),
	m_game_name(Text(Vec3(20, 20, -0.9f), m_game->GetName(), colors::white)),
	m_name_label(Text(Vec3(165, 80, -0.9f), "Name", colors::white)),
	m_name_value(Text(Vec3(235, 80, -0.9f), "")),
	m_tid_label(Text(Vec3(165, 102, -0.9f), "ID Number", colors::white)),
	m_tid_value(Text(Vec3(235, 102, -0.9f), "")),
	m_time_played_label(Text(Vec3(165, 124, -0.9f), "Time played", colors::white)),
	m_time_played_value(Text(Vec3(235, 124, -0.9f), "")),
	m_caught_label(Text(Vec3(165, 146, -0.9f), "Pokédex", colors::white)),
	m_caught_value(Text(Vec3(235, 146, -0.9f), "")),
	m_no_save(Text(Vec3(160, 60, -0.9f), "No save data\nfound, press \nto load one\nor insert\na cartridge"))
{
	m_image.Init(spritesheet::game_logo.at(m_game->GetLogo()), sheet);
	if (m_game->HasSave()) {
		m_name_value.Update(m_game->GetPlayerName());
		m_tid_value.Update(m_game->GetTrainerId());
		m_time_played_value.Update(m_game->GetTimePlayed());
		m_caught_value.Update(m_game->GetDexCaught());
	}
}

void GameInfo::DrawLines() {
	// Title
	C2D_DrawRectSolid(25, 20, 0, 270, 30, colors::title_background);
	C2D_DrawRectSolid(20, 25, 0, 5, 25, colors::title_background);
	C2D_DrawRectSolid(295, 25, 0, 5, 25, colors::title_background);
	m_game_name.DrawLinesCenteredXY(Vec2(280, 30));

	// Game logo
	m_image.DrawLines(Vec3(30, 50, 0), Vec2(1, 1));

	// Box
	C2D_DrawRectSolid(20, 50, 0, 280, 170, colors::game_info_background);

	if (m_game->HasSave()) {
		DrawInfo();
	} else {
		DrawNoSaveLines();
	}
}

void GameInfo::DrawInfo() {
	C2D_DrawRectSolid(160, 80, 0, 70, 20, colors::title_background);
	C2D_DrawRectSolid(230, 80, 0, 60, 20, colors::white);
	m_name_label.DrawLinesCenteredXY(Vec2(60, 20), 0.4f);
	m_name_value.DrawLinesCenteredY(20, 0.4f);

	C2D_DrawRectSolid(160, 102, 0, 70, 20, colors::title_background);
	C2D_DrawRectSolid(230, 102, 0, 60, 20, colors::white);
	m_tid_label.DrawLinesCenteredXY(Vec2(60, 20), 0.4f);
	m_tid_value.DrawLinesCenteredY(20, 0.4f);

	C2D_DrawRectSolid(160, 124, 0, 70, 20, colors::title_background);
	C2D_DrawRectSolid(230, 124, 0, 60, 20, colors::white);
	m_time_played_label.DrawLinesCenteredXY(Vec2(60, 20), 0.4f);
	m_time_played_value.DrawLinesCenteredY(20, 0.4f);

	C2D_DrawRectSolid(160, 146, 0, 70, 20, colors::title_background);
	C2D_DrawRectSolid(230, 146, 0, 60, 20, colors::white);
	m_caught_label.DrawLinesCenteredXY(Vec2(60, 20), 0.4f);
	m_caught_value.DrawLinesCenteredY(20, 0.4f);
}

void GameInfo::DrawNoSaveLines() {
	C2D_DrawRectSolid(165, 60, 0, 120, 120, colors::info_background);
	C2D_DrawRectSolid(160, 65, 0, 5, 110, colors::info_background);
	C2D_DrawRectSolid(285, 65, 0, 5, 110, colors::info_background);
	m_no_save.DrawLinesCenteredXY(Vec2(130, 120));
}


void GameInfo::DrawNoSaveCircles() {
	C2D_DrawCircleSolid(165, 65, 0, 5, colors::info_background);
	C2D_DrawCircleSolid(165, 175, 0, 5, colors::info_background);
	C2D_DrawCircleSolid(285, 65, 0, 5, colors::info_background);
	C2D_DrawCircleSolid(285, 175, 0, 5, colors::info_background);
}

void GameInfo::DrawCircles() {
	// Title
	C2D_DrawCircleSolid(25, 25, 0, 5, colors::title_background);
	C2D_DrawCircleSolid(295, 25, 0, 5, colors::title_background);

	if (!m_game->HasSave()) {
		DrawNoSaveCircles();
	}
}

void GameInfo::Update(C2D_SpriteSheet& sheet, Game* game) {
	m_game = game;
	m_game_name.Update(m_game->GetName());
	m_name_value.Update(m_game->GetPlayerName());
	m_tid_value.Update(m_game->GetTrainerId());
	m_time_played_value.Update(m_game->GetTimePlayed());
	m_caught_value.Update(m_game->GetDexCaught());
	m_image.Init(spritesheet::game_logo.at(m_game->GetLogo()), sheet);
}
