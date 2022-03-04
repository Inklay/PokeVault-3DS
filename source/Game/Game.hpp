#ifndef GAME
#define GAME

#include "../core/source/Save/ASave.hpp"
#include <string>
#include <memory>

class Game {
public:
	static bool is_compatible(std::string name);
	bool has_save(void);
	std::string get_name(void);
	std::string get_box_art(void);
	std::string get_logo(void);
	virtual void save_init(void) = 0;

protected:
	static std::unique_ptr<ASave> m_save;
	bool m_has_save;
	std::string m_name;
	std::string m_box_art;
	std::string m_logo;
};

#endif // !GAME
