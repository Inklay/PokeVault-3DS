#ifndef ARROW_POINTER_HPP
#define ARROW_POINTER_HPP

#include "../utils/Vec3.hpp"

class Arrow_Pointer {
public:
	Arrow_Pointer(Vec3 pos);
	void draw_lines(void);
	void draw_circles(void);
private:
	float m_off;
	float m_dir;
	Vec3 m_pos;
};

#endif // !ARROW_POINTER_HPP
