#ifndef TEXT_HPP
#define TEXT_HPP

#include <string>
#include <citro2d.h>
#include "../utils/Vec2.hpp"
#include "./UIElement.hpp"
#include "./Colors.hpp"

class Text : public UIElement {
public:
	enum class CenterMode {
		BOTH,
		X,
		Y
	};
	Text(Vec3 pos, std::string text, u32 color = colors::black);
	~Text(void);
	void DrawLines(void);
	void DrawLinesCenteredXY(Vec2 size, float font_size = 0.5f);
	void DrawLinesCenteredY(int y, float font_size = 0.5f);
	void DrawLinesCenteredX(int x, float font_size = 0.5f);
	void DrawCircles(void) {};
	void Update(std::string text);

private:
	C2D_Text m_text;
	C2D_TextBuf m_text_buf;
	u32 m_color;
};

#endif // !TEXT_HPP