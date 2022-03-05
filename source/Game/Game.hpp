#ifndef GAME_HPP
#define GAME_HPP

#include "../core/source/Save/ASave.hpp"
#include <string>
#include <memory>
#include "../scene/current_scene.hpp"

class Game {
public:
	static bool is_compatible(ASave::Game game_version);
	bool has_save(void);
	std::string get_name(void);
	std::string get_box_art(void);
	std::string get_logo(void);
	ASave::Game get_version(void);
	virtual void init_save(void) = 0;
	void open_save(void);
	virtual void set_save(std::string path) = 0;
	std::string get_file_extension(void);
	std::unique_ptr<ASave> save;

protected:
	ASave::Game m_game;
	bool m_has_save;
	std::string m_name;
	std::string m_box_art;
	std::string m_logo;
	std::string m_file_extension;
};

#endif // !GAME_HPP
