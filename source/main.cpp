#include <3ds.h>
#include <citro2d.h>
#include "./UI/Game_Art.hpp"
#include <memory>
#include <vector>
#include <iostream>

int main(int argc, char** argv) {
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	consoleInit(GFX_BOTTOM, NULL);
	romfsInit();
	
	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);

	std::vector<std::unique_ptr<UI_Element>> elem;
	const u32 color_clear = C2D_Color32(0x00, 0x00, 0x00, 0x00);
	Vec3 pos1 = Vec3(100, 100, 0);

	elem.emplace_back(std::make_unique<Game_Art>(pos1, "Platiunm", "Platinum.png"));

	while (aptMainLoop()) {
		hidScanInput();
		u32 kDown = hidKeysDown();

		if (kDown & KEY_START)
			break;
		
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, color_clear);
		C2D_SceneBegin(top);

		for (auto& e : elem)
			e->draw_lines();
		for (auto& e : elem)
			e->draw_circles();

		C3D_FrameEnd(0);
	}
	romfsExit();
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}
