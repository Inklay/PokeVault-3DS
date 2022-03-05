#ifndef INFO_BOX_HPP
#define INFO_BOX_HPP

#include "./UI_Element.hpp"
#include "../utils/Vec3.hpp"
#include "../utils/Vec2.hpp"
#include <string>
#include "./Text.hpp"

class Box : public UI_Element {
public:
	Box(Vec3 pos, Vec2 size, std::string text, u32 color, bool visible = true);
	void draw_lines(void);
	void draw_circles(void);
	void update(bool visible);

private:
	Vec3 m_pos;
	Vec2 m_size;
	Text m_text;
	bool m_visible;
	u32 m_color;
};

#endif // !INFO_BOX_HPP
