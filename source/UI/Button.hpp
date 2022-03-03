#ifndef BUTTON
#define BUTTON

#include "./UI_Element.hpp"
#include <string>
#include "../utils/Vec3.hpp"
#include <citro2d.h>

class Button : UI_Element {
public:
	Button(Vec3 pos, Vec3 size, std::string text, bool locked = false, bool selected = false);
	void draw_lines(void);
	void draw_circles(void);

private:
	bool m_is_selected;
	bool m_is_locked;
	std::string m_text;
	Vec3 m_pos;
	Vec3 m_size;
	static const u32 m_default_color = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
};

#endif // !BUTTON
