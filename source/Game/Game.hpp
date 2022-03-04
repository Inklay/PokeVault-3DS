#ifndef GAME_HPP
#define GAME_HPP

#include "../core/source/Save/ASave.hpp"
#include <string>
#include <memory>

class Game {
public:
	static bool is_compatible(ASave::Game game_version);
	bool has_save(void);
	std::string get_name(void);
	std::string get_box_art(void);
	std::string get_logo(void);
	ASave::Game get_version(void);
	virtual void save_init(void) = 0;

protected:
	ASave::Game m_game;
	std::unique_ptr<ASave> m_save;
	bool m_has_save;
	std::string m_name;
	std::string m_box_art;
	std::string m_logo;
};

#endif // !GAME_HPP
