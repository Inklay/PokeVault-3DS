#ifndef BUTTON
#define BUTTON

#include "./UI_Element.hpp"
#include <string>
#include "../utils/Vec3.hpp"
#include "../utils/Vec2.hpp"
#include <citro2d.h>
#include "./Text.hpp"

class Button : public UI_Element {
public:
	Button(Vec3 pos, Vec2 size, std::string text, bool locked = false, bool selected = false);
	void draw_lines(void);
	void draw_circles(void);

private:
	u32 get_color(void);

	bool m_is_selected;
	bool m_is_locked;
	Vec2 m_size;
	static const u32 m_default_color = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
	static const u32 m_locked_color = C2D_Color32(0xAA, 0xAA, 0xAA, 0xFF);
	static const u32 m_selected_color = C2D_Color32(0xF2, 0x8F, 0x24, 0xFF);
	Text m_text;
};

#endif // !BUTTON
