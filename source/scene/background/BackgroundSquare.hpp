#ifndef BACKGROUNDSQUARE_HPP
#define BACKGROUNDSQUARE_HPP

#include "../../utils/Vec3.hpp"
#include <citro2d.h>

class BackgroundSquare {
public:
	BackgroundSquare(Vec3 pos, float speed, int size, u32 color);
	void DrawTop();
	void DrawBottom();
	bool IsDone();

private:
	Vec3 m_pos;
	float m_speed;
	int m_size;
	u32 m_color;
	bool m_done;
};

#endif // !BACKGROUNDSQUARE_HPP
