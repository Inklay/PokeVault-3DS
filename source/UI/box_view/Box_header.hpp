#ifndef BOX_HEADER_HPP
#define BOX_HEADER_HPP

#include "../UI_Element.hpp"
#include "../Button.hpp"

class Box_Header : public UI_Element {
public:
	Box_Header(std::string text, bool is_selected, int m_fix);
	void draw_lines(void);
	void draw_circles(void);
	void update(std::string text, bool is_box_selected, bool is_name_selected);

private:
	bool m_is_selected;
	int m_x_fix;
	Button m_box_name;
	Text m_left;
	Text m_right;
	Text m_l;
	Text m_r;
};

#endif // !BOX_HEADER_HPP
