#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "./UI_Element.hpp"
#include <citro2d.h>
#include "../utils/Vec2.hpp"
#include "../utils/Vec3.hpp"

class Image : public UI_Element {
public:
	Image(void);
	Image(Vec3 pos, Vec2 size, int sprite_idx, C2D_SpriteSheet& sheet);
	void init(int sprite_idx, C2D_SpriteSheet& sheet);
	void draw_lines(void);
	void draw_lines(Vec3 pos, Vec2 size);
	void draw_circles(void);

private:
	C2D_Image m_image;
	Vec3 m_pos;
	Vec2 m_size;
};

#endif // !IMAGE_HPP