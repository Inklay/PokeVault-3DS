#ifndef GAME_SELECT
#define GAME_SELECT

#include "./Scene.hpp"
#include <citro2d.h>
#include <string>
#include <array>
#include <utility>

class Game_Select : public Scene {
public:
	void load(std::vector<std::unique_ptr<UI_Element>>& top_elem,
		std::vector<std::unique_ptr<UI_Element>>& bottom_elem);
	void unload(void);

private:
	C2D_SpriteSheet m_sheet;
	static const std::array<std::pair<std::string, std::string>, 5> m_games;
};

#endif // !GAME_SELECT
