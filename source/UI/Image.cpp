#include "./Image.hpp"

Image::Image(void) {}

Image::Image(Vec3 pos, Vec2 size, int sprite_idx, C2D_SpriteSheet& sheet) {
	m_pos = pos;
	m_size = size;
	m_image = C2D_SpriteSheetGetImage(sheet, sprite_idx);
}

void Image::init(int sprite_idx, C2D_SpriteSheet& sheet) {
	m_image = C2D_SpriteSheetGetImage(sheet, sprite_idx);
}

void Image::draw_lines(void) {
	C2D_DrawImageAt(m_image, m_pos.x, m_pos.y, m_pos.z, nullptr, m_size.x, m_size.y);
}

void Image::draw_lines(Vec3 pos, Vec2 size) {
	C2D_DrawImageAt(m_image, pos.x, pos.y, pos.z, nullptr, size.x, size.y);
}

void Image::draw_circles(void) {}
