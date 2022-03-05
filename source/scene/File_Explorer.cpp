#include "./File_Explorer.hpp"
#include "./current_scene.hpp"
#include "../UI/Header.hpp"
#include "../UI/Footer.hpp"
#include "../UI/Image.hpp"
#include "../UI/file_explorer/File.hpp"
#include "../Game/current_game.hpp"
#include "../utils/SpriteSheet.hpp"

void File_Explorer::load(std::vector<std::shared_ptr<UI_Element>>& top_elem,
	std::vector<std::shared_ptr<UI_Element>>& bottom_elem) {
	top_elem.clear();
	bottom_elem.clear();
	scene::load = false;
	m_current_path = "sdmc:/";

	m_game_logo_sheet = C2D_SpriteSheetLoad("romfs:/gfx/game_logo.t3x");

	top_elem.emplace_back(std::make_shared<Header>("Opening save for " + game::current()->get_name()));
	top_elem.emplace_back(std::make_shared<Image>(Vec3(136, 41, 0), Vec2(1, 1),
		spritesheet::game_logo.at(game::current()->get_logo()), m_game_logo_sheet));
	
	bottom_elem.emplace_back(std::make_unique<Footer>(" select     back"));
	for (size_t i = 0; i < 4; i++) {
		Vec3 pos = Vec3(30, 15 + 50 * i, 0);
		bottom_elem.emplace_back(std::make_unique<File>(pos, "", i == 0));
	}
	update(0);
}

void File_Explorer::unload(void) {
	C2D_SpriteSheetFree(m_game_logo_sheet);
}

void File_Explorer::update(u32 key_down) {
	bool found = false;
	for (const auto& entry : std::filesystem::directory_iterator(m_current_path)) {
		if (entry.is_directory() || entry.path().extension() == game::current()->get_file_extension()) {
			if (!found) {
				found = true;
				m_selected = entry;
			}
		}
	}
}
