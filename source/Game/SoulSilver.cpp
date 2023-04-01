#include "./SoulSilver.hpp"
#include "../config/Config.hpp"
#include "../App.hpp"

SoulSilver::SoulSilver(App* app) :
	Game(app)
{
	m_has_save = m_app->GetConfig().GetKeyValue("save_location", "soulsilver") == "none";
	m_name = "Pokémon Soul Silver Version";
	m_box_art = "SoulSilver.png";
	m_logo = "SoulSilver_EN.png";
	m_game = pksm::GameVersion::SS;
}

void SoulSilver::SetSave(std::string path) {
	m_has_save = path == "none";
	m_app->GetConfig().GetKeyValue("save_location", "soulsilver") = path;
}
