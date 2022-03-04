#ifndef COLORS
#define COLORS

#include <citro2d.h>

namespace colors {
	static constexpr u32 base = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
	static constexpr u32 locked = C2D_Color32(0xAA, 0xAA, 0xAA, 0xFF);
	static constexpr u32 selected = C2D_Color32(0xF2, 0x8F, 0x24, 0xFF);
	static constexpr u32 header_bottom = C2D_Color32(0xAE, 0xF0, 0x62, 0xFF);
	static constexpr u32 header_top = C2D_Color32(0xDA, 0xF0, 0xB9, 0xFF);
	static constexpr u32 header_shadow_bottom = C2D_Color32(0x21, 0x21, 0x21, 0x00);
	static constexpr u32 header_shadow_top = C2D_Color32(0xB1, 0xB1, 0xB1, 0x30);
	static constexpr u32 background_top = C2D_Color32(0xA4, 0xD6, 0x6B, 0xFF);
	static constexpr u32 background_middle = C2D_Color32(0x70, 0xAC, 0x65, 0xFF);
	static constexpr u32 background_bottom= C2D_Color32(0x3B, 0x82, 0x5F, 0xFF);
}

#endif // !COLORS
