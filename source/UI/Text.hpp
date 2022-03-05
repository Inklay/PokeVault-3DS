#ifndef TEXT_HPP
#define TEXT_HPP

#include <string>
#include <citro2d.h>
#include "../utils/Vec2.hpp"
#include "./UI_Element.hpp"
#include "./Colors.hpp"

class Text : public UI_Element {
public:
	enum class center_mode {
		BOTH,
		X,
		Y
	};
	Text(Vec3 pos, std::string text, u32 color = colors::black);
	~Text(void);
	void draw_lines(void);
	void draw_lines_centered_XY(Vec2 size);
	void draw_lines_centered_Y(int y);
	void draw_lines_centered_X(int y);
	void draw_circles(void);
	void update(std::string text);

private:
	C2D_Text m_text;
	C2D_TextBuf m_text_buf;
	u32 m_color;
};

#endif // !TEXT_HPP