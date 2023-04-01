#include "./FileExplorer.hpp"
#include "../utils/SpriteSheet.hpp"
#include "../scene/GameSelect.hpp"
#include "../App.hpp"

FileExplorer::FileExplorer(App* app) :
	m_current_path("sdmc:/"),
	m_idx(0),
	m_game_logo_sheet(C2D_SpriteSheetLoad("romfs:/gfx/game_logo.t3x")),
	m_header_top(Header("Opening save for " + m_app->GetSelectedGame()->GetName())),
	m_game_logo_top(Image(Vec3(136, 41, 0), Vec2(1, 1), spritesheet::game_logo.at(m_app->GetSelectedGame()->GetLogo()), m_game_logo_sheet)),
	m_footer_top(Footer(m_current_path, GFX_TOP, Text::CenterMode::BOTH)),
	m_footer_bottom(Footer(" select     back", GFX_BOTTOM, Text::CenterMode::Y)),
	m_text_box_bottom(TextBox(Vec3(30, 90, 0), Vec2(260, 60), "No save found in this folder", colors::info_background, false)),
	Scene(app)
{
	m_type = Scene::FILE_EXPLORER;
	for (size_t i = 0; i < 4; i++) {
		Vec3 pos = Vec3(30, 15 + 50 * i, 0);
		m_files_bottom.emplace_back(File(pos, "", i == 0));
	}
	m_selected = &m_files_bottom.at(0);
	Update(0);
}

FileExplorer::~FileExplorer() {
	C2D_SpriteSheetFree(m_game_logo_sheet);
}

void FileExplorer::DrawTop() {
	// Lines
	m_header_top.DrawLines();
	m_game_logo_top.DrawLines();
	m_footer_top.DrawLines();
}

void FileExplorer::DrawBottom() {
	// Lines
	m_text_box_bottom.DrawLines();
	m_footer_bottom.DrawLines();
	for (File f : m_files_bottom) {
		f.DrawLines();
	}

	// Circles
	m_text_box_bottom.DrawCircles();
	m_footer_bottom.DrawCircles();
	for (File f : m_files_bottom) {
		f.DrawCircles();
	}
}

void FileExplorer::Update(u32 key_down) {
	if (key_down & KEY_B) {
		if (m_current_path == "sdmc:/") {
			m_app->ChangeScene(GAME_SELECT);
			return;
		}
		size_t pos = m_current_path.find_last_of('/');
		if (pos == 5) {
			pos++;
		}
		m_current_path = m_current_path.substr(0, pos);
		m_idx = 0;
		m_footer_top.Update(m_current_path);
	}
	if (key_down & KEY_DOWN || key_down & KEY_CPAD_DOWN || key_down & KEY_CSTICK_DOWN || key_down & KEY_DDOWN) {
		m_idx++;
	}
	if (m_idx > 0 && (key_down & KEY_UP || key_down & KEY_CPAD_UP || key_down & KEY_CSTICK_UP || key_down & KEY_UP)) {
		m_idx--;
	}
	if (key_down & KEY_A) {
		if (m_selected->type == UIElement::Type::FILE) {
			if (m_entry.is_directory()) {
				if (m_current_path != "sdmc:/") {
					m_current_path += "/";
				}
				m_current_path += m_entry.path().filename().string();
				m_idx = 0;
				m_footer_top.Update(m_current_path);
			} else {
				try {
					m_app->GetSelectedGame()->SetSave(m_entry.path().string());
					m_app->GetConfig().Save();
					ShowPopup("Save successfully loaded !", "Valid");
				} catch (...) {
					ShowPopup("Invalid or corrupted save file !", "Invalid");
				}
			}
		} else if (m_selected->type == UIElement::Type::POPUP) {
			if (GetPopupName() == "valid") {
				m_app->ChangeScene(GAME_SELECT);
				return;
			} else if (GetPopupName() == "invalid") {
				HidePopup();
			}
		}
	}

	size_t i = 0;
	size_t vector_i = 0;
	bool found = false;
	std::filesystem::directory_entry last;
	for (const auto& entry : std::filesystem::directory_iterator(m_current_path)) {
		if (entry.is_directory() || entry.path().extension() == m_app->GetSelectedGame()->GetFileExtension()) {
			last = entry;
			if (!found) {
				found = true;
			}
			if (i < m_idx + 4 && i >= m_idx) {
				if (vector_i == 0) {
					m_entry = entry;
				}
				m_files_bottom.at(vector_i + 1).Update(entry.path().filename().string(), true);
				vector_i++;
			}
			i++;
		}
	}
	if (found && vector_i == 0) {
		m_idx--;
		m_files_bottom.at(vector_i + 1).Update(last.path().filename().string(), true);
		vector_i++;
	}
	for (; vector_i < 4; vector_i++) {
		m_files_bottom.at(vector_i + 1).Update("", false);
	}
	m_text_box_bottom.Update(!found);
}
