#ifndef COLORS
#define COLORS

#include <citro2d.h>

namespace colors {
	static const u32 base = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
	static const u32 locked = C2D_Color32(0xAA, 0xAA, 0xAA, 0xFF);
	static const u32 selected = C2D_Color32(0xF2, 0x8F, 0x24, 0xFF);
	static const u32 header_bottom = C2D_Color32(0xAE, 0xF0, 0x62, 0xFF);
	static const u32 header_top = C2D_Color32(0xDA, 0xF0, 0xB9, 0xFF);
}

#endif // !COLORS
