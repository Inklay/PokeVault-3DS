#ifndef TEXT_HPP
#define TEXT_HPP

#include <string>
#include <citro2d.h>
#include "../utils/Vec2.hpp"
#include "./UI_Element.hpp"

class Text : public UI_Element {
public:
	Text(Vec3 pos, std::string text);
	~Text(void);
	void draw_lines(void);
	void draw_lines(Vec2 size);
	void draw_circles(void);

private:
	C2D_Text m_text;
	C2D_TextBuf m_text_buf;
};

#endif // !TEXT_HPP