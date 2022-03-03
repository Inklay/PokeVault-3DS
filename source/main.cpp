#include <3ds.h>
#include <citro2d.h>
#include <iostream>
#include "./UI/Button.hpp"
#include "./core/source/Save/Game/SavePL.hpp"
#include <memory>

int main(int argc, char** argv)
{
	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);

	const u32 clrClear = C2D_Color32(0x00, 0x00, 0x00, 0x00);

	//SavePL save = SavePL("sdmc:/PL.SAV");
	//std::cout << save.get_username() << std::endl;

	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();

	Vec3 pos = Vec3(0, 0, 0);
	Vec3 size = Vec3(100, 20, 0);
	Button test = Button(pos, size, "test");
	std::unique_ptr<C3D_RenderTarget> bottom = std::unique_ptr<C3D_RenderTarget>(C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT));

	while (aptMainLoop())
	{
		hidScanInput();
		u32 kDown = hidKeysDown();
		
		if (kDown & KEY_START)
			break;

		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(bottom.get(), clrClear);
		C2D_SceneBegin(bottom.get());
		test.draw_lines();
		test.draw_circles();
		C3D_FrameEnd(0);
	}

	gfxExit();
	return 0;
}
