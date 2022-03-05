#include "Popup.hpp"
#include <citro2d.h>
#include "Colors.hpp"

Popup::Popup(std::string text, std::string name) :
m_text(Text(Vec3(70, 70, 0), text)),
m_button(Button(Vec3(120, 150, 0.1f), Vec2(80, 20), "OK", false, true)) {
	this->name = name;
	type = AButton::Type::POPUP;
}

void Popup::draw_lines(void) {
	C2D_DrawRectSolid(55, 50, 0.1f, 210, 140, colors::popup_background);
	C2D_DrawRectSolid(50, 55, 0.1f, 5, 130, colors::popup_background);
	C2D_DrawRectSolid(265, 55, 0.1f, 5, 130, colors::popup_background);
	m_text.draw_lines_centered_XY(Vec2(180, 60));
	m_button.draw_lines();
}

void Popup::draw_circles(void) {
	C2D_DrawCircleSolid(55, 55, 0.1f, 5, colors::popup_background);
	C2D_DrawCircleSolid(55, 185, 0.1f, 5, colors::popup_background);
	C2D_DrawCircleSolid(265, 55, 0.1f, 5, colors::popup_background);
	C2D_DrawCircleSolid(265, 185, 0.1f, 5, colors::popup_background);
	m_button.draw_circles();
}
