#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <citro2d.h>
#include <vector>
#include "./BackgroundSquare.hpp"

class Background {
public:
	Background();
	void DrawTop();
	void DrawBottom();

private:
	std::vector<BackgroundSquare> m_squares;
	const std::vector<u32> m_colors;
};

#endif // !BACKGROUND_HPP
