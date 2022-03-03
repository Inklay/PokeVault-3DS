#include <3ds.h>
#include <iostream>
#include "./core/source/Save/Game/SavePL.hpp"

int main(int argc, char** argv)
{
	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);

	SavePL save = SavePL("sdmc:/PL.SAV");
	std::cout << save.get_username() << std::endl;

	while (aptMainLoop())
	{
		hidScanInput();
		u32 kDown = hidKeysDown();
		
		if (kDown & KEY_START)
			break;

		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
	}

	gfxExit();
	return 0;
}
