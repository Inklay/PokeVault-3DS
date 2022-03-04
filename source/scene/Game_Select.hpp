#ifndef GAME_SELECT_HPP
#define GAME_SELECT_HPP

#include "./Scene.hpp"
#include <citro2d.h>
#include <string>
#include <array>
#include "../Game/Game.hpp"

class Game_Select : public Scene {
public:
	void load(std::vector<std::shared_ptr<UI_Element>>& top_elem,
		std::vector<std::shared_ptr<UI_Element>>& bottom_elem);
	void unload(void);

private:
	C2D_SpriteSheet m_game_art_sheet;
	C2D_SpriteSheet m_game_logo_sheet;
	C2D_Font m_font;
};

#endif // !GAME_SELECT_HPP
