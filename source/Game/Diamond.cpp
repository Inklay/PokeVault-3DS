#include "./Diamond.hpp"
#include "../config/Config.hpp"
#include "../App.hpp"

Diamond::Diamond(App* app) :
	Game(app)
{
	m_has_save = m_app->GetConfig().GetKeyValue("save_location", "diamond") == "none";
	m_name = "Pokémon Diamond Version";
	m_box_art = "Diamond.png";
	m_logo = "Diamond_EN.png";
	m_game = pksm::GameVersion::D;
}

void Diamond::SetSave(std::string path) {
	m_has_save = path == "none";
	m_app->GetConfig().GetKeyValue("save_location", "diamond") = path;
}
