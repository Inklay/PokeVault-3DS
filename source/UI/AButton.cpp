#include "./AButton.hpp"
#include "./Colors.hpp"

u32 AButton::GetColor() const {
	if (m_is_locked)
		return colors::locked;
	else if (m_is_selected)
		return colors::selected;
	return colors::white;
}

void AButton::SetSelected(bool selected) {
	m_is_selected = selected;
}
