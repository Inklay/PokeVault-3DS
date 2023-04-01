#include "./Config.hpp"
#include <filesystem>

Config::Config() :
	m_file(mINI::INIFile("sdmc:/3ds/Pokevault/config.ini"))
{
	if (!m_file.read(m_ini)) {
		std::filesystem::create_directories("sdmc:/3ds/Pokevault");
	}

	m_edited = false;
	LoadKey("save_location", "soulsilver");
	LoadKey("save_location", "heartgold");
	LoadKey("save_location", "platinum");
	LoadKey("save_location", "pearl");
	LoadKey("save_location", "diamond");

	if (m_edited)
		Save();
}

std::string Config::LoadKey(std::string section, std::string key) {
	if (m_ini.has(section)) {
		if (m_ini[section].has(key)) {
			return m_ini[section][key];
		} else {
			m_edited = true;
			m_ini[section][key] = "none";
			return "none";
		}
	} else {
		m_edited = true;
		m_ini[section][key] = "none";
		return "none";
	}
}

std::string Config::GetKeyValue(std::string section, std::string key) {
	return m_ini[section][key];
}

void Config::Save() {
	m_file.write(m_ini);
}

void Config::SetKeyValue(std::string section, std::string key, std::string value) {
	m_ini[section][key] = value;
	Save();
}
