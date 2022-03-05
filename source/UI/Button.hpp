#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "./AButton.hpp"
#include <string>
#include "../utils/Vec3.hpp"
#include "../utils/Vec2.hpp"
#include <citro2d.h>
#include "./Text.hpp"
#include <functional>

class Button : public AButton {
public:
	Button(Vec3 pos, Vec2 size, std::string text, std::function<void(void)> func, bool locked = false, bool selected = false);
	void draw_lines(void);
	void draw_circles(void);
	void pressed(void);

protected:
	Vec2 m_size;
	Text m_text;
	std::function<void(void)> m_func;
};

#endif // !BUTTON_HPP
