#ifndef BOX_HPP
#define BOX_HPP

#include "../UIElement.hpp"
#include "../Button.hpp"
#include <3ds.h>
#include <map>
#include "./BoxHeader.hpp"
#include <vector>
#include "../../PKSM-Core/include/sav/Sav.hpp"

class Box : public UIElement {
public:
	Box(bool selected, gfxScreen_t screen, std::unique_ptr<pksm::Sav> const& save);
	void DrawLines(void);
	void DrawCircles(void);
	void Update(bool selected);

private:
	void LoadBox(void);
	bool HasFemaleSprite(std::unique_ptr<pksm::PKX> const& pkm);
	std::string GetPokemonSprite(std::unique_ptr<pksm::PKX> const& pkm);
	std::string GetSpriteName(std::unique_ptr<pksm::PKX> const& pkm);

	std::unique_ptr<pksm::Sav> const& m_save;
	bool m_is_selected;
	int m_x_fix;
	BoxHeader m_header;
	std::map<std::string, C2D_Image> m_sprites;
	std::vector<C2D_SpriteSheet> m_sheets;
};

#endif // !BOX_HPP
