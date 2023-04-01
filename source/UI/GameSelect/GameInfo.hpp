#ifndef GAMEINFO_HPP
#define GAMEINFO_HPP

#include "../UIElement.hpp"
#include "../Text.hpp"
#include <memory>
#include "../../Game/Game.hpp"
#include <citro2d.h>
#include "../Image.hpp"
#include <vector>

class GameInfo : public UIElement {
public:
	GameInfo(C2D_SpriteSheet& sheet, Game* game);
	void DrawLines();
	void DrawCircles();
	void Update(C2D_SpriteSheet& sheet, Game* game);

private:
	void DrawInfo();
	void DrawNoSaveLines();
	void DrawNoSaveCircles();

	Game* m_game;
	Text m_game_name;
	Text m_name_label;
	Text m_name_value;
	Text m_tid_label;
	Text m_tid_value;
	Text m_time_played_label;
	Text m_time_played_value;
	Text m_caught_label;
	Text m_caught_value;
	Text m_no_save;
	Image m_image;
};

#endif // !GAMEINFO_HPP
