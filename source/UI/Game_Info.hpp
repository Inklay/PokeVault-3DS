#ifndef GAME_INFO_HPP
#define GAME_INFO_HPP

#include "./UI_Element.hpp"
#include <memory>
#include "../Game/Game.hpp"
#include <citro2d.h>

class Game_Info : public UI_Element {
public:
	Game_Info(C2D_Font font);
	void draw_lines(void);
	void draw_circles(void);

private:
	C2D_Font m_font;
};

#endif // !GAME_INFO_HPP
