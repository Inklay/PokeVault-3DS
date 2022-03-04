#ifndef HEADER_HPP
#define HEADER_HPP

#include "./Text.hpp"

class Header : public UI_Element {
public:
	Header(std::string text, C2D_Font font);
	void draw_lines(void);
	void draw_circles(void) {}

private:
	Text m_text;
};

#endif // !HEADER_HPP
