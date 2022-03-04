#ifndef BACKGROUND_SQUARE_HPP
#define BACKGROUND_SQUARE_HPP

#include "../../utils/Vec3.hpp"
#include <citro2d.h>

class Background_Square {
public:
	Background_Square(Vec3 pos, float speed, int size, u32 color);
	~Background_Square(void);
	void update_top(void);
	void update_bottom(void);
	bool is_done(void);

private:
	Vec3 m_pos;
	float m_speed;
	int m_size;
	u32 m_color;
	bool m_done;
};

#endif // !BACKGROUND_SQUARE_HPP
