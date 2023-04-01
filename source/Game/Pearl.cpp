#include "./Pearl.hpp"
#include "../config/Config.hpp"
#include "../App.hpp"

Pearl::Pearl(App* app) :
	Game(app)
{
	m_has_save = m_app->GetConfig().GetKeyValue("save_location", "pearl") == "none";
	m_name = "Pokémon Pearl Version";
	m_box_art = "Pearl.png";
	m_logo = "Pearl_EN.png";
	m_game = pksm::GameVersion::P;
}

void Pearl::SetSave(std::string path) {
	m_has_save = path == "none";
	m_app->GetConfig().GetKeyValue("save_location", "pearl") = path;
}
