#ifndef GAME_ART_HPP
#define GAME_ART_HPP

#include "./Button.hpp"
#include <string>
#include <citro2d.h>

class Game_Art : public Button {
public:
	Game_Art(Vec3 pos, std::string image_path, C2D_SpriteSheet& sheet, C2D_Font font, bool is_locked, bool is_selected);
	void draw_lines(void);
	void draw_circles(void);

private:
	C2D_Image m_image;
};

#endif // !GAME_ART_HPP
