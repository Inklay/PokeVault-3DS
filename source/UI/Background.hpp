#ifndef BACKGROUND
#define BACKGROUND

#include "./UI_Element.hpp"

class Background : public UI_Element {
public:
	enum class Screen {
		BOTTOM,
		TOP
	};

	Background(Screen screen);
	void draw_lines(void);
	void draw_circles(void) {}

private:
	Screen m_screen;
};

#endif // !BACKGROUND
