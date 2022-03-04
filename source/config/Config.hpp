#ifndef CONFIG
#define CONFIG

#include <string>
#include "../mINI/src/mini/ini.h"

class Config {
public:
	Config();
	std::string PL_save_path;

private:
	std::string load_key(std::string section, std::string key, std::string default_value, mINI::INIStructure ini);
	bool m_edited;
};

#endif // !CONFIG

namespace config {
	static Config current = Config();
};
