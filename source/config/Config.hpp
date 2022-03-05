#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include "../mINI/src/mini/ini.h"

class Config {
public:
	Config();
	void save(void);
	std::string soulsilver_save_path;
	std::string heartgold_save_path;
	std::string platinum_save_path;
	std::string pearl_save_path;
	std::string diamond_save_path;

private:
	std::string load_key(std::string section, std::string key, std::string default_value);
	bool m_edited;
	mINI::INIStructure m_ini;
	mINI::INIFile m_file;
};

namespace config {
	extern Config current;
};

#endif // !CONFIG_HPP
