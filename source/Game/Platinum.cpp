#include "./Platinum.hpp"
#include "../config/Config.hpp"
#include "../PKSM-Core/include/sav/SavPT.hpp"
#include "../scene/FileExplorer.hpp"
#include "../App.hpp"

Platinum::Platinum(App* app) :
	Game(app)
{
	m_save_location_config_name = "platinum";
	m_has_save = m_app->GetConfig().GetKeyValue("save_location", m_save_location_config_name) != "none";
	m_name = "Pokémon Platinum Version";
	m_box_art = "Platinum.png";
	m_logo = "Platinum_EN.png";
	m_game = pksm::GameVersion::Pt;
	m_file_extension = ".SAV";
	m_size = 0x80000;
	GetBaseData();
}

void Platinum::SetSave(std::string path) {
	m_has_save = path != "none";
	m_app->GetConfig().GetKeyValue("save_location", m_save_location_config_name) = path;
	if (m_has_save) {
		m_is_init = false;
		GetBaseData();
	}
}
