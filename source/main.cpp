#include <3ds.h>
#include "./UI/UI_Element.hpp"
#include "./scene/current_scene.hpp"
#include "./scene/background/Background.hpp"
#include <time.h>
#include "./config/Config.hpp"


namespace config {
	Config current = Config();
}

namespace scene {
	std::unique_ptr<Scene> current_scene = std::make_unique<Game_Select>();
	bool load = false;
}

int main(int argc, char** argv) {
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	cfguInit();
	romfsInit();
	
	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	C3D_RenderTarget* bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);

	const u32 color_clear = C2D_Color32(0x00, 0x00, 0x00, 0x00);
	Background bg;

	std::vector<std::shared_ptr<UI_Element>> top_elem;
	std::vector<std::shared_ptr<UI_Element>> bottom_elem;

	scene::current_scene->load(top_elem, bottom_elem);
	srand(time(NULL));
	size_t hold_timer = 0;
	size_t hold_threshold = 20;

	while (aptMainLoop()) {
		hidScanInput();
		u32 key_down = hidKeysDown();
		u32 key_held = hidKeysHeld();
		
		if (hold_timer == hold_threshold) {
			key_down = key_down | key_held;
			hold_timer = 0;
			if (hold_threshold != 10)
				hold_threshold = 10;
		}

		// DEBUG ONLY, WILL BE REMOVED WHEN SHIPPING PUBLIC VERSION
		if (key_down & KEY_L && key_down & KEY_R) {
			config::current.platinum_save_path = "none";
			config::current.save();
		}

		if (key_down & KEY_START)
			break;
		
		if (key_held != 0)
			hold_timer++;
		else if (hold_timer != 0) {
			hold_timer = 0;
			hold_threshold = 20;
		}

		scene::current_scene->update(top_elem, bottom_elem, key_down);

		if (scene::load)
			scene::current_scene->load(top_elem, bottom_elem);

		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, color_clear);
		C2D_SceneBegin(top);

		bg.update_top();
		for (auto& e : top_elem)
			e->draw_lines();
		for (auto& e : top_elem)
			e->draw_circles();

		C2D_TargetClear(bottom, color_clear);
		C2D_SceneBegin(bottom);

		bg.update_bottom();
		for (auto& e : bottom_elem)
			e->draw_lines();
		for (auto& e : bottom_elem)
			e->draw_circles();

		C3D_FrameEnd(0);
	}
	scene::current_scene->unload();
	romfsExit();
	cfguExit();
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}
