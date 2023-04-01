#ifndef GAMEART_HPP
#define GAMEART_HPP

#include "../AButton.hpp"
#include <string>
#include <citro2d.h>
#include "../ArrowPointer.hpp"
#include "../Image.hpp"

class GameArt : public AButton {
public:
	GameArt(Vec3 pos, std::string image_path, C2D_SpriteSheet& sheet, bool is_locked, bool is_selected);
	void DrawLines();
	void DrawCircles();

private:
	Image m_image;
	ArrowPointer m_pointer;
};

#endif // !GAMEART_HPP
