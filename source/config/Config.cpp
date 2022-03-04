#include "./Config.hpp"

Config::Config(void) {
	mINI::INIFile file("sdmc:/3ds/Pokevault/config.ini");
	mINI::INIStructure ini;

	file.read(ini);

	m_edited = false;
	PL_save_path = load_key("save_location", "platinum", "none", ini);

	if (m_edited)
		file.write(ini);
}

std::string Config::load_key(std::string section, std::string key, std::string default_value, mINI::INIStructure ini) {
	if (ini.has(section)) {
		if (ini[section].has(key))
			return ini[section][key];
		else {
			m_edited = true;
			ini[section][key] = default_value;
			return default_value;
		}
	} else {
		m_edited = true;
		ini[section][key] = default_value;
		return default_value;
	}
}
