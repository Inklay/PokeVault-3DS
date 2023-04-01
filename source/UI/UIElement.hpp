#ifndef UIELEMENT_HPP
#define UIELEMENT_HPP

#include "../utils/Vec3.hpp"

class UIElement {
public:
	enum class Type {
		GAME_ART,
		BUTTON,
		POPUP,
		FILE,
		OTHER
	};

	virtual void DrawLines(void) = 0;
	virtual void DrawCircles(void) = 0;
	Type type = Type::OTHER;

protected:
	Vec3 m_pos;
};

#endif // !UIELEMENT_HPP
