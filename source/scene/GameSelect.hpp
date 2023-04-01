#ifndef GAMESELECT_HPP
#define GAMESELECT_HPP

#include "./Scene.hpp"
#include <citro2d.h>
#include <string>
#include <array>
#include "../Game/Game.hpp"
#include "../UI/Header.hpp"
#include "../UI/GameSelect/GameArt.hpp"
#include "../UI/GameSelect/GameInfo.hpp"
#include "../UI/Popup.hpp"

class GameSelect : public Scene {
public:
	GameSelect(App* app);
	~GameSelect();
	void DrawTop();
	void DrawBottom();
	void Update(u32 key_down);

private:
	GameInfo m_game_info_bottom;
	std::vector<GameArt> m_game_arts_top;
	Header m_header_top;
	C2D_SpriteSheet m_game_art_sheet;
	C2D_SpriteSheet m_game_logo_sheet;
};

#endif // !GAMESELECT_HPP
