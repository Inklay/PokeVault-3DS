#ifndef ARROWPOINTER_HPP
#define ARROWPOINTER_HPP

#include "../utils/Vec3.hpp"
#include "UIElement.hpp"

class ArrowPointer : UIElement {
public:
	ArrowPointer(Vec3 pos);
	void DrawLines();
	void DrawCircles();
private:
	float m_off;
	float m_dir;
	Vec3 m_pos;
};

#endif // !ARROWPOINTER_HPP
