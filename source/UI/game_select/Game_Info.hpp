#ifndef GAME_INFO_HPP
#define GAME_INFO_HPP

#include "../UI_Element.hpp"
#include "../Text.hpp"
#include <memory>
#include "../../Game/Game.hpp"
#include <citro2d.h>
#include "../Image.hpp"
#include <vector>

class Game_Info : public UI_Element {
public:
	Game_Info(C2D_SpriteSheet& sheet);
	void draw_lines(void);
	void draw_circles(void);

private:
	void draw_info(void);
	void draw_no_save_lines(void);
	void draw_no_save_circles(void);

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

#endif // !GAME_INFO_HPP
