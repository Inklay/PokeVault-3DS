#ifndef FOOTER_HPP
#define FOOTER_HPP

#include <3ds.h>
#include "./Text.hpp"

class Footer : public UIElement {
public:
	Footer(std::string text, gfxScreen_t screen, Text::CenterMode mode);
	void DrawLines();
	void DrawCircles() {}
	void Update(std::string text);

private:
	Text m_text;
	gfxScreen_t m_screen;
	Text::CenterMode m_mode;
};

#endif // !FOOTER_HPP
