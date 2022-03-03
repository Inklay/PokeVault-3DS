#ifndef GAME_ART
#define GAME_ART

#include "./UI_Element.hpp"
#include <string>
#include <citro2d.h>

class Game_Art : public UI_Element {
public:
	Game_Art(Vec3 pos, std::string name, std::string image_path);
	void draw_lines(void);
	void draw_circles(void);

private:
	std::string m_game_name;
	C2D_Image m_image;
};

#endif // !GAME_ART