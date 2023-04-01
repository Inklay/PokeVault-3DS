#include "./GameSelect.hpp"
#include <3ds.h>
#include "../App.hpp"

GameSelect::GameSelect(App* app) :
	m_game_art_sheet(C2D_SpriteSheetLoad("romfs:/gfx/game_art.t3x")),
	m_game_logo_sheet(C2D_SpriteSheetLoad("romfs:/gfx/game_logo.t3x")),
	m_header_top(Header("Choose a game to open")),
	//m_header_top(Header(m_app->GetGames().at(0)->GetBoxArt())),
	m_game_info_bottom(m_game_logo_sheet, m_app->GetSelectedGame()),
	Scene(app)
{
	m_type = Scene::GAME_SELECT;

	bool found_compatible_game = false;
	for (size_t i = 0; i < m_app->GetGames().size(); i++) {
		int x = 24 + 94 * (i % 4);
		int y = 30 + 24 + 94 * (i / 4);
		bool is_locked = !Game::IsCompatible(m_app->GetGames().at(i)->GetVersion());
		bool is_selected = false;
		if (!is_locked && !found_compatible_game) {
			is_selected = true;
			found_compatible_game = true;
			m_app->SetGameIndex(i);
			m_game_info_bottom.Update(m_game_logo_sheet, m_app->GetSelectedGame());
		}
		m_game_arts_top.emplace_back(GameArt(Vec3(x, y, 0), m_app->GetGames().at(i)->GetBoxArt(), m_game_art_sheet, is_locked, is_selected));
		if (is_selected) {
			m_selected = &m_game_arts_top.at(m_game_arts_top.size() - 1);
			/*try {
				m_app->GetSelectedGame()->InitSave();
			} catch (...) {
				ShowPopup("Missing or corrupted save file !", "invalid");
				m_app->GetSelectedGame()->SetSave("none");
			}*/
		}
	}
}

GameSelect::~GameSelect() {
	C2D_SpriteSheetFree(m_game_art_sheet);
	C2D_SpriteSheetFree(m_game_logo_sheet);
}

void GameSelect::DrawTop() {
	// Lines
	m_header_top.DrawLines();
	for (GameArt ga : m_game_arts_top) {
		ga.DrawLines();
	}

	//Circles
	for (GameArt ga : m_game_arts_top) {
		ga.DrawCircles();
	}
}

void GameSelect::DrawBottom() {
	// Lines
	m_game_info_bottom.DrawLines();

	// Circles
	m_game_info_bottom.DrawCircles();
}

void GameSelect::Update(u32 key_down) {
	if (key_down & KEY_A) {
		if (m_selected->type == UIElement::Type::GAME_ART) {
			m_app->GetSelectedGame()->OpenGame();
		} else if (m_selected->type == UIElement::Type::POPUP) {
			HidePopup();
		}
	}
}
