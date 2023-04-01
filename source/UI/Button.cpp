#include "./Button.hpp"
#include "./Colors.hpp"
#include <3ds.h>

Button::Button(Vec3 pos, Vec2 size, std::string text, bool locked, bool selected) :
m_text(Text(Vec3(pos.x, pos.y, 0), text)),
m_pointer(ArrowPointer(Vec3(pos.x - 10, pos.y, pos.z + 0.1f))) {
	m_is_locked = locked;
	m_is_selected = selected;
	m_pos = pos;
	m_size = size;
	type = UIElement::Type::BUTTON;
}

void Button::DrawLines() {
	C2D_DrawRectSolid(m_pos.x + m_size.y / 2, m_pos.y, m_pos.z, m_size.x - m_size.y, m_size.y, GetColor());
	m_text.DrawLinesCenteredXY(m_size);

	if (m_is_selected)
		m_pointer.DrawLines();
}

void Button::DrawCircles() {
	const int radius = m_size.y / 2;
	C2D_DrawCircleSolid(m_pos.x + radius, m_pos.y + radius, m_pos.z, radius, GetColor());
	C2D_DrawCircleSolid(m_pos.x + m_size.x - radius, m_pos.y + radius, m_pos.z, radius, GetColor());

	if (m_is_selected)
		m_pointer.DrawCircles();
}

void Button::Update(std::string text, bool is_selected, bool is_locked) {
	m_is_selected = is_selected;
	m_is_locked = is_locked;
	m_text.Update(text);
}
