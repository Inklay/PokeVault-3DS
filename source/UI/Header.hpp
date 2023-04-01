#ifndef HEADER_HPP
#define HEADER_HPP

#include "./Text.hpp"

class Header : public UIElement {
public:
	Header(std::string text);
	void DrawLines(void);
	void DrawCircles(void) {}

private:
	Text m_text;
};

#endif // !HEADER_HPP
