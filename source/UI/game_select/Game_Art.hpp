#ifndef GAME_ART_HPP
#define GAME_ART_HPP

#include "../Button.hpp"
#include <string>
#include <citro2d.h>
#include "../Arrow_Pointer.hpp"
#include "../Image.hpp"

class Game_Art : public Button {
public:
	Game_Art(Vec3 pos, std::string image_path, C2D_SpriteSheet& sheet, std::function<void(void)> func, bool is_locked, bool is_selected);
	void draw_lines(void);
	void draw_circles(void);

private:
	Image m_image;
	Arrow_Pointer m_pointer;
	float m_pointer_off;
	float m_pointer_dir;
};

#endif // !GAME_ART_HPP
