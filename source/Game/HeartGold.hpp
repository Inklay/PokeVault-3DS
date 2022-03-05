#ifndef HEARTGOLD_HPP
#define HEARTGOLD_HPP

#include "./Game.hpp"

class HeartGold : public Game {
public:
	HeartGold(void);
	void init_save(void);
	void set_save(std::string path);
};

#endif // !HEARTGOLD_HPP
