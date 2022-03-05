#ifndef GAME_INFO_HPP
#define GAME_INFO_HPP

#include "../UI_Element.hpp"
#include <memory>
#include "../../Game/Game.hpp"
#include <citro2d.h>
#include "../Image.hpp"

class Game_Info : public UI_Element {
public:
	Game_Info(C2D_SpriteSheet& sheet);
	void draw_lines(void);
	void draw_circles(void);

private:
	void draw_info(void);
	void draw_no_save_lines(void);
	void draw_no_save_circles(void);

	Image m_image;
};

#endif // !GAME_INFO_HPP