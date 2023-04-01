#ifndef SOULSILVER_HPP
#define SOULSILVER_HPP

#include "./Game.hpp"

class SoulSilver : public Game {
public:
	SoulSilver(App* app);
	void SetSave(std::string path);
};

#endif // !SOULSILVER_HPP
