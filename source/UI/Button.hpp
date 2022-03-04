#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "./UI_Element.hpp"
#include <string>
#include "../utils/Vec3.hpp"
#include "../utils/Vec2.hpp"
#include <citro2d.h>
#include "./Text.hpp"

class Button : public UI_Element {
public:
	Button(Vec3 pos, Vec2 size, std::string text, C2D_Font font, bool locked = false, bool selected = false);
	void draw_lines(void);
	void draw_circles(void);

protected:
	u32 get_color(void);

	bool m_is_selected;
	bool m_is_locked;
	Vec2 m_size;
	Text m_text;
};

#endif // !BUTTON_HPP
