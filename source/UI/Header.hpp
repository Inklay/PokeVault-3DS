#ifndef HEADER
#define HEADER

#include "./Text.hpp"

class Header : public UI_Element {
public:
	Header(std::string text);
	void draw_lines(void);
	void draw_circles(void);

private:
	Text m_text;
};

#endif // !HEADER
