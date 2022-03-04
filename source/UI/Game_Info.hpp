#ifndef GAME_INFO_HPP
#define GAME_INFO_HPP

#include "./UI_Element.hpp"
#include <memory>
#include "../Game/Game.hpp"
#include <citro2d.h>

class Game_Info : public UI_Element {
public:
	Game_Info(C2D_Font font, C2D_SpriteSheet& sheet);
	void draw_lines(void);
	void draw_circles(void);

private:
	C2D_Font m_font;
	C2D_Image m_image;
};

#endif // !GAME_INFO_HPP
