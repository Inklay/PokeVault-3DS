#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include "../mINI/src/mini/ini.h"

class Config {
public:
	Config();
	void Save();
	void SetKeyValue(std::string section, std::string key, std::string value);
	std::string GetKeyValue(std::string section, std::string key);

private:
	std::string LoadKey(std::string section, std::string key);
	bool m_edited;
	mINI::INIStructure m_ini;
	mINI::INIFile m_file;
};

#endif // !CONFIG_HPP
