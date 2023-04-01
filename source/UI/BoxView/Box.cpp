#include "./Box.hpp"
#include "../Colors.hpp"
#include <filesystem>
#include <sstream>

Box::Box(bool selected, gfxScreen_t screen, std::unique_ptr<pksm::Sav> const& save) :
	m_save(save),
	m_is_selected(selected),
	m_x_fix((screen == GFX_BOTTOM) ? 0 : 40),
	m_header(BoxHeader(m_save->boxName(m_save->currentBox()), selected, m_x_fix))
{
	LoadBox();
}

void Box::DrawLines() {
	u32 title_color = m_is_selected ? colors::title_background : colors::title_unselected_background;
	u32 box_color = m_is_selected ? colors::white : colors::box_unselected_background;

	// Box name
	m_header.DrawLines();

	// Box body
	C2D_DrawRectSolid(30 + m_x_fix, 35, 0, 260, 200, box_color);

	if (m_is_selected) {
		C2D_DrawLine(31 + m_x_fix, 35, title_color, 31 + m_x_fix, 235, title_color, 2, 0);
		C2D_DrawLine(289 + m_x_fix, 35, title_color, 289 + m_x_fix, 235, title_color, 2, 0);
		C2D_DrawLine(30 + m_x_fix, 234, title_color, 289 + m_x_fix, 234, title_color, 2, 0);
	}
}

void Box::DrawCircles() {
	m_header.DrawCircles();

	for (size_t x = 0; x < 6; x++) {
		for (size_t y = 0; y < 5; y++) {
			C2D_DrawCircleSolid(60 + m_x_fix + 40 * x, 60 + 37 * y, 0, 16, colors::game_info_background);
		}
	}

	// This is not in the same loop to avoid changing state in citro 2d too much
	for (size_t x = 0; x < 6; x++) {
		for (size_t y = 0; y < 5; y++) {
			std::unique_ptr<pksm::PKX> pkm = m_save->pkm(x + y * 6);
			if (pkm->PID() != 0) {
				std::string sprite_path = GetPokemonSprite(pkm);
				C2D_DrawImageAt(m_sprites.at(sprite_path), 36 + m_x_fix + 40 * x, 28 + 37 * y, 0, nullptr, 48.0f / 68.0f, 48.0f / 56.0f);
			}
		}
	}
}

void Box::LoadBox(void) {
	for (size_t i = 0; i < 30; i++) {
		std::unique_ptr<pksm::PKX> pkm = m_save->pkm(i);
		if (pkm->PID() != 0) {
			std::string sprite = GetPokemonSprite(pkm);
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

bool Box::HasFemaleSprite(std::unique_ptr<pksm::PKX> const& pkm) {
	const int nat_dex_id = (int)pkm->species();
	return  (pkm->gender() == pksm::Gender::Female && (
		nat_dex_id == 902 ||
		nat_dex_id == 592 ||
		nat_dex_id == 449 ||
		nat_dex_id == 450 ||
		nat_dex_id == 876 ||
		nat_dex_id == 593 ||
		nat_dex_id == 678 ||
		nat_dex_id == 25 ||
		nat_dex_id == 668 ||
		nat_dex_id == 521 ||
		nat_dex_id == 202));
}

std::string Box::GetPokemonSprite(std::unique_ptr<pksm::PKX> const &pkm) {
	std::stringstream ss;
	ss << "romfs:/gfx/" << GetSpriteName(pkm);
	if (HasFemaleSprite(pkm))
		ss << "-f";
	ss << ".t3x";
	return ss.str();
}

std::string Box::GetSpriteName(std::unique_ptr<pksm::PKX> const& pkm) {
	const int nat_dex_id = (int)pkm->species();
	std::stringstream ss;
	if (nat_dex_id < 10) {
		ss << "00" << nat_dex_id;
	} else if (nat_dex_id < 100) {
		ss << "0" << nat_dex_id;
	} else {
		ss << nat_dex_id;
	}
	return ss.str();
}

void Box::Update(bool selected) {
	for (C2D_SpriteSheet sheet : m_sheets)
		C2D_SpriteSheetFree(sheet);
	m_sheets.clear();
	m_sprites.clear();
	m_is_selected = selected;
	LoadBox();
	m_header.Update(m_save->boxName(m_save->currentBox()), m_is_selected, false);
}
