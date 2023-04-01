#ifndef HEARTGOLD_HPP
#define HEARTGOLD_HPP

#include "./Game.hpp"

class HeartGold : public Game {
public:
	HeartGold(App* app);
	void SetSave(std::string path);
};

#endif // !HEARTGOLD_HPP
