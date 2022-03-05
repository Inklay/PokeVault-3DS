#ifndef GAME_ART_HPP
#define GAME_ART_HPP

#include "../AButton.hpp"
#include <string>
#include <citro2d.h>
#include "../Arrow_Pointer.hpp"
#include "../Image.hpp"
#include <functional>

class Game_Art : public AButton {
public:
	Game_Art(Vec3 pos, std::string image_path, C2D_SpriteSheet& sheet, std::function<void(void)> func, bool is_locked, bool is_selected);
	void draw_lines(void);
	void draw_circles(void);
	void pressed(void);

private:
	Image m_image;
	Arrow_Pointer m_pointer;
	std::function<void(void)> m_func;
};

#endif // !GAME_ART_HPP
