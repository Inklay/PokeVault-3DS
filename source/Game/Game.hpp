#ifndef GAME
#define GAME

#include "../core/source/Save/ASave.hpp"
#include <string>
#include <memory>

class Game {
public:
	static bool is_compatible(std::string name);
	//static void change_game(ASave::Game game);

private:
	static std::unique_ptr<ASave> m_save;
};

#endif // !GAME
