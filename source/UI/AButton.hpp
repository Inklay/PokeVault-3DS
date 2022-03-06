#ifndef  ABUTTON_HPP
#define ABUTTON_HPP

#include "./UI_Element.hpp"
#include <citro2d.h>

class AButton : public UI_Element {
public:
	u32 get_color(void);
	virtual void draw_lines(void) = 0;
	virtual void draw_circles(void) = 0;
	void set_selected(bool selected);

protected:
	bool m_is_selected;
	bool m_is_locked;
	
};

#endif // ! ABUTTON_HPP
