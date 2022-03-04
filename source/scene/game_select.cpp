#include "./scene.hpp"
#include <citro2d.h>
#include "../UI/Game_Art.hpp"

namespace scene {
	namespace game_select{

		static C2D_SpriteSheet sheet;

		void load(std::vector<std::unique_ptr<UI_Element>>& elem) {
			sheet = C2D_SpriteSheetLoad("romfs:/gfx/game_art.t3x");

			Vec3 pos1 = Vec3(20, 20, 0);
			Vec3 pos2 = Vec3(100, 20, 0);
			Vec3 pos3 = Vec3(180, 20, 0);

			elem.emplace_back(std::make_unique<Game_Art>(pos1, "Platinum", "Platinum.png", sheet));
			elem.emplace_back(std::make_unique<Game_Art>(pos2, "Pearl", "Pearl.png", sheet));
			elem.emplace_back(std::make_unique<Game_Art>(pos3, "Diamond", "Diamond.png", sheet));
		}

		void unload(std::vector<std::unique_ptr<UI_Element>>& elem) {
			elem.clear();
			C2D_SpriteSheetFree(sheet);
		}
	};
};
