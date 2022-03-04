#include "./scene.hpp"
#include <citro2d.h>
#include "../UI/Game_Art.hpp"
#include "../UI/Header.hpp"
#include "../UI/Background.hpp"
#include <array>
#include <utility>

namespace scene {
	namespace game_select{

		static C2D_SpriteSheet sheet;
		static const std::array<std::pair<std::string, std::string>, 5> games = {
			std::pair<std::string, std::string>("Soul Silver" , "SoulSilver.png"),
			std::pair<std::string, std::string>("Heart Gold" , "HeartGold.png"),
			std::pair<std::string, std::string>("Platinum" , "Platinum.png"),
			std::pair<std::string, std::string>("Pearl" , "Pearl.png"),
			std::pair<std::string, std::string>("Diamond" , "Diamond.png"),
		};

		void load(std::vector<std::unique_ptr<UI_Element>>& elem) {
			sheet = C2D_SpriteSheetLoad("romfs:/gfx/game_art.t3x");

			elem.emplace_back(std::make_unique<Background>(Background::Screen::TOP));
			elem.emplace_back(std::make_unique<Header>("Choose a game to open"));

			for (size_t i = 0; i < games.size(); i++) {
				int x = 24 + 94 * (i % 4);
				int y = 30 + 24 + 94 * (i / 4);
				elem.emplace_back(std::make_unique<Game_Art>(Vec3(x, y, 0), games[i].first, games[i].second, sheet));
			}
		}

		void unload(std::vector<std::unique_ptr<UI_Element>>& elem) {
			elem.clear();
			C2D_SpriteSheetFree(sheet);
		}
	};
};
