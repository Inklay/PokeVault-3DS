#ifndef PEARL_HPP
#define PEARL_HPP

#include "./Game.hpp"

class Pearl : public Game {
public:
	Pearl(App* app);
	void SetSave(std::string path);
};

#endif // !PEARL_HPP
