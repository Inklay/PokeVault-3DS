#ifndef FOOTER_HPP
#define FOOTER_HPP

#include <3ds.h>
#include "./Text.hpp"

class Footer : public UI_Element {
public:
	Footer(std::string text, gfxScreen_t screen, Text::center_mode mode);
	void draw_lines(void);
	void draw_circles(void) {}
	void update(std::string text);

private:
	Text m_text;
	gfxScreen_t m_screen;
	Text::center_mode m_mode;
};

#endif // !FOOTER_HPP
