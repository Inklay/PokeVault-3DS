#include "./Arrow_Pointer.hpp"
#include "./Colors.hpp"
#include <citro2d.h>

void Arrow_Pointer::draw_lines(Vec3 pos) {
	C2D_DrawLine(pos.x, pos.y, colors::white,
		pos.x, pos.y + 20, colors::white, 6, pos.z);
	C2D_DrawLine(pos.x, pos.y + 20, colors::white,
		pos.x + 10, pos.y + 10, colors::white, 6, pos.z);
	C2D_DrawLine(pos.x + 10, pos.y + 10, colors::white,
		pos.x, pos.y, colors::white, 6, pos.z);

	C2D_DrawTriangle(pos.x, pos.y, colors::arrow_pointer,
		pos.x, pos.y + 20, colors::arrow_pointer,
		pos.x + 10, pos.y + 10, colors::arrow_pointer, pos.z + 1);
}

void Arrow_Pointer::draw_circles(Vec3 pos) {
	C2D_DrawCircleSolid(pos.x, pos.y, pos.z, 3, colors::white);
	C2D_DrawCircleSolid(pos.x, pos.y + 20, pos.z, 3, colors::white);
	C2D_DrawCircleSolid(pos.x + 10, pos.y + 10, pos.z, 3, colors::white);
}
