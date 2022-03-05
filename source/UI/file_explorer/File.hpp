#ifndef FILE_HPP
#define FILE_HPP

#include "../AButton.hpp"
#include <string>

class File : public AButton {
public:
	File(Vec3 pos, std::string text, bool selected);
	void draw_lines(void);
	void draw_circles(void);

private:
	Vec3 m_pos;
};

#endif // !FILE_HPP
