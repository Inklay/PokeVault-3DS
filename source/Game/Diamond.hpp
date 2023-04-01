#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "./Game.hpp"

class Diamond : public Game {
public:
	Diamond(App* app);
	void SetSave(std::string path);
};

#endif // !DIAMOND_HPP
