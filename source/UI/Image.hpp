#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "./UIElement.hpp"
#include <citro2d.h>
#include "../utils/Vec2.hpp"
#include "../utils/Vec3.hpp"

class Image : public UIElement {
public:
	Image();
	Image(Vec3 pos, Vec2 size, int sprite_idx, C2D_SpriteSheet& sheet);
	void Init(int sprite_idx, C2D_SpriteSheet& sheet);
	void DrawLines();
	void DrawLines(Vec3 pos, Vec2 size);
	void DrawCircles() {};

private:
	C2D_Image m_image;
	Vec3 m_pos;
	Vec2 m_size;
};

#endif // !IMAGE_HPP