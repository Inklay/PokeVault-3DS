#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <citro2d.h>
#include <vector>
#include "./Square.hpp"

class Background {
public:
	Background(void);
	void update_top(void);
	void update_bottom(void);

private:
	std::vector<Background_Square> m_squares;
	const std::vector<u32> m_colors;
};

#endif // !BACKGROUND_HPP
