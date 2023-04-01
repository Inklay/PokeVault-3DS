#include "./HeartGold.hpp"
#include "../config/Config.hpp"
#include "../App.hpp"

HeartGold::HeartGold(App* app) :
	Game(app)
{
	m_has_save = m_app->GetConfig().GetKeyValue("save_location", "heartgold") == "none";
	m_name = "Pokémon Heart Gold Version";
	m_box_art = "HeartGold.png";
	m_logo = "HeartGold_EN.png";
	m_game = pksm::GameVersion::HG;
}

void HeartGold::SetSave(std::string path) {
	m_has_save = path == "none";
	m_app->GetConfig().GetKeyValue("save_location", "heartgold") = path;
}
