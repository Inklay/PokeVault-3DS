#include "./Config.hpp"
#include <filesystem>

Config::Config(void) : m_file(mINI::INIFile("sdmc:/3ds/Pokevault/config.ini")) {
	if (!m_file.read(m_ini))
		std::filesystem::create_directories("sdmc:/3ds/Pokevault");

	m_edited = false;
	soulsilver_save_path = load_key("save_location", "soulsilver", "none");
	heartgold_save_path = load_key("save_location", "heartgold", "none");
	platinum_save_path = load_key("save_location", "platinum", "none");
	pearl_save_path = load_key("save_location", "pearl", "none");
	diamond_save_path = load_key("save_location", "diamond", "none");

	if (m_edited)
		m_file.write(m_ini);
}

std::string Config::load_key(std::string section, std::string key, std::string default_value) {
	if (m_ini.has(section)) {
		if (m_ini[section].has(key))
			return m_ini[section][key];
		else {
			m_edited = true;
			m_ini[section][key] = default_value;
			return default_value;
		}
	} else {
		m_edited = true;
		m_ini[section][key] = default_value;
		return default_value;
	}
}

void Config::save(void) {
	m_ini["save_location"]["soulsilver"] = soulsilver_save_path;
	m_ini["save_location"]["heartgold"] = heartgold_save_path;
	m_ini["save_location"]["platinum"] = platinum_save_path;
	m_ini["save_location"]["pearl"] = pearl_save_path;
	m_ini["save_location"]["diamond"] = diamond_save_path;
	m_file.write(m_ini);
}
