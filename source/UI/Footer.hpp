#ifndef FOOTER_HPP
#define FOOTER_HPP

#include "./Text.hpp"

class Footer : public UI_Element {
public:
	Footer(std::string text);
	void draw_lines(void);
	void draw_circles(void) {}

private:
	Text m_text;
};

#endif // !FOOTER_HPP
