#include "./Box.hpp"
#include "../Colors.hpp"
#include <filesystem>
#include <sstream>
#include "../../core/source/Save/Pkm/Base_Pokemon.hpp"

Box::Box(bool selected, Base_Box box, gfxScreen_t screen) :
m_box(box),
m_is_selected(selected),
m_x_fix((screen == GFX_BOTTOM) ? 0 : 40),
m_header(Box_Header(box.get_name(), selected, m_x_fix)) {
	load_box();
}

void Box::draw_lines(void) {
	u32 title_color = m_is_selected ? colors::title_background : colors::title_unselected_background;
	u32 box_color = m_is_selected ? colors::white : colors::box_unselected_background;

	// Box name
	m_header.draw_lines();

	// Box body
	C2D_DrawRectSolid(30 + m_x_fix, 35, 0, 260, 200, box_color);

	if (m_is_selected) {
		C2D_DrawLine(31 + m_x_fix, 35, title_color, 31 + m_x_fix, 235, title_color, 2, 0);
		C2D_DrawLine(289 + m_x_fix, 35, title_color, 289 + m_x_fix, 235, title_color, 2, 0);
		C2D_DrawLine(30 + m_x_fix, 234, title_color, 289 + m_x_fix, 234, title_color, 2, 0);
	}
}

void Box::draw_circles(void) {
	m_header.draw_circles();

	for (size_t x = 0; x < 6; x++) {
		for (size_t y = 0; y < 5; y++) {
			C2D_DrawCircleSolid(60 + m_x_fix + 40 * x, 60 + 37 * y, 0, 16, colors::game_info_background);
		}
	}

	// This is not in the same loop to avoid changing state in citro 2d too much
	for (size_t x = 0; x < 6; x++) {
		for (size_t y = 0; y < 5; y++) {
			Base_Pokemon pkm = m_box.get_pokemon_at(x + y * 6);
			if (pkm.get_PID() != 0) {
				std::string sprite_path = get_pkm_sprite(pkm);
				C2D_DrawImageAt(m_sprites.at(sprite_path), 36 + m_x_fix + 40 * x, 28 + 37 * y, 0, nullptr, 48.0f / 68.0f, 48.0f / 56.0f);
			}
		}
	}
}

void Box::load_box(void) {
	for (size_t i = 0; i < 30; i++) {
		Base_Pokemon pkm = m_box.get_pokemon_at(i);
		if (pkm.get_PID() != 0) {
			std::string sprite = get_pkm_sprite(pkm);
			if (std::filesystem::exists(sprite)) {
				C2D_SpriteSheet sheet = C2D_SpriteSheetLoad(sprite.c_str());
				m_sprites[sprite] = C2D_SpriteSheetGetImage(sheet, 0);
				m_sheets.emplace_back(sheet);
			} else {
				C2D_SpriteSheet sheet = C2D_SpriteSheetLoad("romfs:/gfx/other.t3x");
				m_sprites[sprite] = C2D_SpriteSheetGetImage(sheet, 0);
				m_sheets.emplace_back(sheet);
			}
		}
	}
}

bool Box::has_female_sprite(Base_Pokemon pkm) {
	return  (pkm.get_gender() == Base_Pokemon::Gender::FEMALE && (
		pkm.get_dex_number() == 902 ||
		pkm.get_dex_number() == 592 ||
		pkm.get_dex_number() == 449 ||
		pkm.get_dex_number() == 450 ||
		pkm.get_dex_number() == 876 ||
		pkm.get_dex_number() == 593 ||
		pkm.get_dex_number() == 678 ||
		pkm.get_dex_number() == 25 ||
		pkm.get_dex_number() == 668 ||
		pkm.get_dex_number() == 521 ||
		pkm.get_dex_number() == 202));
}

std::string Box::get_pkm_sprite(Base_Pokemon pkm) {
	std::stringstream ss;
	ss << "romfs:/gfx/" << pkm.get_sprite();
	if (has_female_sprite(pkm))
		ss << "-f";
	ss << ".t3x";
	return ss.str();
}

void Box::update(bool selected, Base_Box box) {
	for (C2D_SpriteSheet sheet : m_sheets)
		C2D_SpriteSheetFree(sheet);
	m_sheets.clear();
	m_sprites.clear();
	m_is_selected = selected;
	m_box = box;
	load_box();
	m_header.update(m_box.get_name(), m_is_selected, false);
}
