#ifndef PLATINUM_HPP
#define PLATINUM_HPP

#include "./Game.hpp"

class Platinum : public Game {
public:
	Platinum(void);
	void init_save(void);
	void set_save(std::string path);
};

#endif // !PLATINUM_HPP
