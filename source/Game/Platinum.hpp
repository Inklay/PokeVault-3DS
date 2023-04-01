#ifndef PLATINUM_HPP
#define PLATINUM_HPP

#include "./Game.hpp"

class Platinum : public Game {
public:
	Platinum(App* app);
	void SetSave(std::string path);
};

#endif // !PLATINUM_HPP
