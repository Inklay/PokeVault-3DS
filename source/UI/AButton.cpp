#include "./AButton.hpp"
#include "./Colors.hpp"

u32 AButton::get_color(void) {
	if (m_is_locked)
		return colors::locked;
	else if (m_is_selected)
		return colors::selected;
	return colors::white;
}