#ifndef COLORS
#define COLORS

#include <citro2d.h>

namespace colors {
	static constexpr u32 white = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
	static constexpr u32 black = C2D_Color32(0x00, 0x00, 0x00, 0xFF);
	static constexpr u32 info_background = C2D_Color32(0xA2, 0xEB, 0xCC, 0xFF);
	static constexpr u32 locked = C2D_Color32(0xAA, 0xAA, 0xAA, 0xFF);
	static constexpr u32 selected = C2D_Color32(0xF2, 0x8F, 0x24, 0xFF);
	static constexpr u32 header_bottom = C2D_Color32(0xAE, 0xF0, 0x62, 0xFF);
	static constexpr u32 header_top = C2D_Color32(0xDA, 0xF0, 0xB9, 0xFF);
	static constexpr u32 header_shadow_bottom = C2D_Color32(0x21, 0x21, 0x21, 0x00);
	static constexpr u32 header_shadow_top = C2D_Color32(0xB1, 0xB1, 0xB1, 0x30);
	static constexpr u32 background_top = C2D_Color32(0xA4, 0xD6, 0x6B, 0xFF);
	static constexpr u32 background_middle = C2D_Color32(0x70, 0xAC, 0x65, 0xFF);
	static constexpr u32 background_bottom= C2D_Color32(0x3B, 0x82, 0x5F, 0xFF);
	static constexpr u32 title_background = C2D_Color32(0x09, 0x75, 0x63, 0xFF);
	static constexpr u32 game_info_background = C2D_Color32(0x09, 0x75, 0x63, 0x30);
	static constexpr u32 arrow_pointer = C2D_Color32(0x41, 0x96, 0x74, 0xFF);
	static constexpr u32 footer_top = C2D_Color32(0xA0, 0xD4, 0x64, 0xFF);
	static constexpr u32 footer_bottom = C2D_Color32(0xC7, 0xE0, 0xA8, 0xFF);
	static constexpr u32 popup_background = C2D_Color32(0xC9, 0xF5, 0xD4, 0xFF);
	static constexpr u32 title_unselected_background = C2D_Color32(0x8F, 0xC9, 0x9C, 0xFF);
	static constexpr u32 box_unselected_background = C2D_Color32(0xD5, 0xF5, 0xDC, 0xFF);
}

#endif // !COLORS
