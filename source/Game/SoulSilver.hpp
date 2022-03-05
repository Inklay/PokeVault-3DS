#ifndef SOULSILVER_HPP
#define SOULSILVER_HPP

#include "./Game.hpp"

class SoulSilver : public Game {
public:
	SoulSilver(void);
	void init_save(void);
	void set_save(std::string path);
};

#endif // !SOULSILVER_HPP
