#ifndef PEARL_HPP
#define PEARL_HPP

#include "./Game.hpp"

class Pearl : public Game {
public:
	Pearl(void);
	void init_save(void);
	void set_save(std::string path);
};

#endif // !PEARL_HPP
