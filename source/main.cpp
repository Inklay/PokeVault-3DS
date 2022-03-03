#include <3ds.h>
#include <citro2d.h>
#include <iostream>
#include "./UI/Button.hpp"
#include "./core/source/Save/Game/SavePL.hpp"
#include <memory>
#include <vector>

int main(int argc, char** argv) {
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	consoleInit(GFX_TOP, NULL);
	C3D_RenderTarget* bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);

	std::vector<std::unique_ptr<UI_Element>> elem;
	const u32 color_clear = C2D_Color32(0x00, 0x00, 0x00, 0x00);
	Vec3 pos1 = Vec3(0, 0, 0);
	Vec3 pos2 = Vec3(0, 20, 0);
	Vec3 pos3 = Vec3(0, 40, 0);
	Vec2 size = Vec2(90, 20);

	Button fun(pos1, size, "test");

	elem.emplace_back(std::make_unique<Button>(pos1, size, "Default"));
	elem.emplace_back(std::make_unique<Button>(pos2, size, "Locked", true));
	elem.emplace_back(std::make_unique<Button>(pos3, size, "Selected", false, true));

	while (aptMainLoop()) {
		hidScanInput();
		u32 kDown = hidKeysDown();

		if (kDown & KEY_START)
			break;
		
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(bottom, color_clear);
		C2D_SceneBegin(bottom);

		for (auto& e : elem)
			e->draw_lines();
		for (auto& e : elem)
			e->draw_circles();

		C3D_FrameEnd(0);
	}
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}
