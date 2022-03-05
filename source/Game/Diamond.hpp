#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "./Game.hpp"

class Diamond : public Game {
public:
	Diamond(void);
	void init_save(void);
	void set_save(std::string path);
};

#endif // !DIAMOND_HPP
