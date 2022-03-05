#ifndef FILE_HPP
#define FILE_HPP

#include "../AButton.hpp"
#include <string>
#include "../Text.hpp"
#include "../Arrow_Pointer.hpp"

class File : public AButton {
public:
	File(Vec3 pos, std::string text, bool selected);
	void draw_lines(void);
	void draw_circles(void);
	void update(std::string text, bool visible);

private:
	Vec3 m_pos;
	bool m_visible;
	Text m_text;
	Arrow_Pointer m_pointer;
};

#endif // !FILE_HPP
