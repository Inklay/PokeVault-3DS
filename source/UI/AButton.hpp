#ifndef  ABUTTON_HPP
#define ABUTTON_HPP

#include "./UIElement.hpp"
#include <citro2d.h>

class AButton : public UIElement {
public:
	u32 GetColor() const;
	virtual void DrawLines() = 0;
	virtual void DrawCircles() = 0;
	void SetSelected(bool selected);

protected:
	bool m_is_selected;
	bool m_is_locked;
};

#endif // ! ABUTTON_HPP
