#include "Popup.hpp"
#include <citro2d.h>
#include "Colors.hpp"

Popup::Popup(std::string text) :
m_text(Text(Vec3(70, 70, 0), text)),
m_button(Button(Vec3(120, 150, 0.2f), Vec2(80, 20), "OK", false, true)) {
	type = UIElement::Type::POPUP;
}

void Popup::DrawLines() {
	C2D_DrawRectSolid(55, 50, 0.2f, 210, 140, colors::popup_background);
	C2D_DrawRectSolid(50, 55, 0.2f, 5, 130, colors::popup_background);
	C2D_DrawRectSolid(265, 55, 0.2f, 5, 130, colors::popup_background);
	m_text.DrawLinesCenteredXY(Vec2(180, 60));
	m_button.DrawLines();
}

void Popup::DrawCircles() {
	C2D_DrawCircleSolid(55, 55, 0.2f, 5, colors::popup_background);
	C2D_DrawCircleSolid(55, 185, 0.2f, 5, colors::popup_background);
	C2D_DrawCircleSolid(265, 55, 0.2f, 5, colors::popup_background);
	C2D_DrawCircleSolid(265, 185, 0.2f, 5, colors::popup_background);
	m_button.DrawCircles();
}

void Popup::Update(std::string text, std::string name) {
	m_text.Update(text);
	m_name = name;
}

std::string Popup::GetName() {
	return m_name;
}
