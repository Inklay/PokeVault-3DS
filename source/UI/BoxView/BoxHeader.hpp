#ifndef BOXHEADER_HPP
#define BOXHEADER_HPP

#include "../UIElement.hpp"
#include "../Button.hpp"

class BoxHeader : public UIElement {
public:
	BoxHeader(std::string text, bool is_selected, int m_fix);
	void DrawLines(void);
	void DrawCircles(void);
	void Update(std::string text, bool is_box_selected, bool is_name_selected);

private:
	bool m_is_selected;
	int m_x_fix;
	Button m_box_name;
	Text m_left;
	Text m_right;
	Text m_l;
	Text m_r;
};
BOXHEADER_HPP
#endif // !BOX_HEADER_HPP
