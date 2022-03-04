#include <3ds.h>
#include <citro2d.h>
#include "./UI/UI_Element.hpp"
#include <memory>
#include <vector>
#include "./scene/scene.hpp"

int main(int argc, char** argv) {
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	romfsInit();
	
	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	C3D_RenderTarget* bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);

	const u32 color_clear = C2D_Color32(0x00, 0x00, 0x00, 0x00);

	std::vector<std::unique_ptr<UI_Element>> top_elem;
	std::vector<std::unique_ptr<UI_Element>> bottom_elem;
	
	scene::game_select::load(top_elem, bottom_elem);

	while (aptMainLoop()) {
		hidScanInput();
		u32 kDown = hidKeysDown();

		if (kDown & KEY_START)
			break;
		
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, color_clear);
		C2D_SceneBegin(top);

		for (auto& e : top_elem)
			e->draw_lines();
		for (auto& e : top_elem)
			e->draw_circles();

		C2D_TargetClear(bottom, color_clear);
		C2D_SceneBegin(bottom);

		for (auto& e : bottom_elem)
			e->draw_lines();
		for (auto& e : bottom_elem)
			e->draw_circles();

		C3D_FrameEnd(0);
	}
	romfsExit();
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}
