#include "./Box.hpp"
#include "../Colors.hpp"
#include <filesystem>
#include <sstream>

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
			if (m_box.get_pokemon_at(x + y * 6).get_PID() != 0) {
				std::string sprite_path = m_box.get_pokemon_at(x + y * 6).get_sprite();
				C2D_DrawImageAt(m_sprites.at(sprite_path), 36 + m_x_fix + 40 * x, 28 + 37 * y, 0, nullptr, 48.0f / 68.0f, 48.0f / 56.0f);
			}
		}
	}
}

void Box::load_box(void) {
	for (size_t i = 0; i < 30; i++) {
		if (m_box.get_pokemon_at(i).get_PID() != 0) {
			std::stringstream ss;
			ss << "romfs:/gfx/" << m_box.get_pokemon_at(i).get_sprite() << ".t3x";
			if (std::filesystem::exists(ss.str())) {
				C2D_SpriteSheet sheet = C2D_SpriteSheetLoad(ss.str().c_str());
				m_sprites[m_box.get_pokemon_at(i).get_sprite()] = C2D_SpriteSheetGetImage(sheet, 0);
				m_sheets.emplace_back(sheet);
			} else {
				C2D_SpriteSheet sheet = C2D_SpriteSheetLoad("romfs:/gfx/other.t3x");
				m_sprites[m_box.get_pokemon_at(i).get_sprite()] = C2D_SpriteSheetGetImage(sheet, 0);
				m_sheets.emplace_back(sheet);
			}
		}
	}
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
