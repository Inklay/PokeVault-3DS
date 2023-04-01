#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include "./UIElement.hpp"
#include "../utils/Vec3.hpp"
#include "../utils/Vec2.hpp"
#include <string>
#include "./Text.hpp"

class TextBox : public UIElement {
public:
	TextBox(Vec3 pos, Vec2 size, std::string text, u32 color, bool visible = true);
	void DrawLines(void);
	void DrawCircles(void);
	void Update(bool visible);

private:
	Vec3 m_pos;
	Vec2 m_size;
	Text m_text;
	bool m_visible;
	u32 m_color;
};

#endif // !TEXTBOX_HPP
