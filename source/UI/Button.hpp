#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "./AButton.hpp"
#include <string>
#include "../utils/Vec3.hpp"
#include "../utils/Vec2.hpp"
#include <citro2d.h>
#include "./Text.hpp"
#include "./Arrow_Pointer.hpp"

class Button : public AButton {
public:
	Button(Vec3 pos, Vec2 size, std::string text, bool locked = false, bool selected = false);
	//Button(std::string text, bool locked = false, bool selected = false);
	//void init(Vec3 pos, Vec2 size);
	void draw_lines(void);
	void draw_circles(void);
	void update(std::string text, bool is_selected, bool is_locked);

protected:
	Vec2 m_size;
	Text m_text;
	Arrow_Pointer m_pointer;
};

#endif // !BUTTON_HPP
