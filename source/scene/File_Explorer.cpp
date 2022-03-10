#include "./File_Explorer.hpp"
#include "./current_scene.hpp"
#include "../UI/Header.hpp"
#include "../UI/Footer.hpp"
#include "../UI/Image.hpp"
#include "../UI/Popup.hpp"
#include "../UI/file_explorer/File.hpp"
#include "../Game/current_game.hpp"
#include "../utils/SpriteSheet.hpp"
#include <3ds.h>
#include "../scene/Game_Select.hpp"
#include "../UI/Text_Box.hpp"
#include "../config/Config.hpp"

File_Explorer::File_Explorer(void) {
	m_name = "File Explorer";
}

void File_Explorer::load(std::vector<std::shared_ptr<UI_Element>>& top_elem,
	std::vector<std::shared_ptr<UI_Element>>& bottom_elem) {
	top_elem.clear();
	bottom_elem.clear();
	scene::load = false;
	m_current_path = "sdmc:/";
	m_idx = 0;

	m_game_logo_sheet = C2D_SpriteSheetLoad("romfs:/gfx/game_logo.t3x");

	top_elem.emplace_back(std::make_shared<Header>("Opening save for " + game::current()->get_name()));
	top_elem.emplace_back(std::make_shared<Image>(Vec3(136, 41, 0), Vec2(1, 1),
		spritesheet::game_logo.at(game::current()->get_logo()), m_game_logo_sheet));
	top_elem.emplace_back(std::make_unique<Footer>(m_current_path, GFX_TOP, Text::center_mode::BOTH));

	bottom_elem.emplace_back(std::make_unique<Footer>(" select     back", GFX_BOTTOM, Text::center_mode::Y));
	for (size_t i = 0; i < 4; i++) {
		Vec3 pos = Vec3(30, 15 + 50 * i, 0);
		bottom_elem.emplace_back(std::make_unique<File>(pos, "", i == 0));
	}
	bottom_elem.emplace_back(std::make_unique<Text_Box>(Vec3(30, 90, 0), Vec2(260, 60),
		"No save found in this folder", colors::info_background, false));
	m_selected = std::dynamic_pointer_cast<AButton>(bottom_elem.at(1));
	update(top_elem, bottom_elem, 0);
}

void File_Explorer::unload(void) {
	C2D_SpriteSheetFree(m_game_logo_sheet);
}

void File_Explorer::update(std::vector<std::shared_ptr<UI_Element>>& top_elem,
	std::vector<std::shared_ptr<UI_Element>>& bottom_elem, u32 key_down) {
	if (key_down & KEY_B) {
		if (m_current_path == "sdmc:/") {
			scene::change_scene<Game_Select>();
			return;
		}
		size_t pos = m_current_path.find_last_of('/');
		if (pos == 5)
			pos++;
		m_current_path = m_current_path.substr(0, pos);
		m_idx = 0;
		std::shared_ptr<Footer> footer = std::dynamic_pointer_cast<Footer>(top_elem.at(2));
		footer->update(m_current_path);
	}
	if (key_down & KEY_DOWN || key_down & KEY_CPAD_DOWN || key_down & KEY_CSTICK_DOWN || key_down & KEY_DDOWN)
		m_idx++;
	if (m_idx > 0 && (key_down & KEY_UP || key_down & KEY_CPAD_UP || key_down & KEY_CSTICK_UP || key_down & KEY_UP))
		m_idx--;
	if (key_down & KEY_A) {
		if (m_selected->type == UI_Element::Type::FILE) {
			if (m_entry.is_directory()) {
				if (m_current_path != "sdmc:/")
					m_current_path += "/";
				m_current_path += m_entry.path().filename().u8string();
				m_idx = 0;
				std::shared_ptr<Footer> footer = std::dynamic_pointer_cast<Footer>(top_elem.at(2));
				footer->update(m_current_path);
			} else {
				try {
					game::current()->set_save(m_entry.path().u8string());
					config::current.save();
					bottom_elem.emplace_back(std::make_unique<Popup>("Save successfully loaded !", "valid"));
				} catch (...) {
					bottom_elem.emplace_back(std::make_unique<Popup>("Invalid or corrupted save file !", "invalid"));
				}
				update_selected(std::dynamic_pointer_cast<AButton>(bottom_elem.at(6)));
			}
		} else if (m_selected->type == UI_Element::Type::POPUP) {
			std::shared_ptr<Popup> popup = std::dynamic_pointer_cast<Popup>(bottom_elem.at(6));
			if (popup->name == "valid") {
				scene::change_scene<Game_Select>();
				return;
			} else if (popup->name == "invalid") {
				bottom_elem.erase(bottom_elem.begin() + 6);
				update_selected(std::dynamic_pointer_cast<AButton>(bottom_elem.at(1)));
			}
		}
	}

	size_t i = 0;
	size_t vector_i = 0;
	bool found = false;
	std::filesystem::directory_entry last;
	for (const auto& entry : std::filesystem::directory_iterator(m_current_path)) {
		if (entry.is_directory() || entry.path().extension() == game::current()->get_file_extension()) {
			last = entry;
			if (!found)
				found = true;
			if (i < m_idx + 4 && i >= m_idx) {
				if (vector_i == 0)
					m_entry = entry;
				std::shared_ptr<File> file = std::dynamic_pointer_cast<File>(bottom_elem.at(vector_i + 1));
				file->update(entry.path().filename().u8string(), true);
				vector_i++;
			}
			i++;
		}
	}
	if (found && vector_i == 0) {
		m_idx--;
		std::shared_ptr<File> file = std::dynamic_pointer_cast<File>(bottom_elem.at(vector_i + 1));
		file->update(last.path().filename().u8string(), true);
		vector_i++;
	}
	for (; vector_i < 4; vector_i++) {
		std::shared_ptr<File> file = std::dynamic_pointer_cast<File>(bottom_elem.at(vector_i + 1));
		file->update("", false);
	}
	std::shared_ptr<Text_Box> box = std::dynamic_pointer_cast<Text_Box>(bottom_elem.at(5));
	box->update(!found);
}
