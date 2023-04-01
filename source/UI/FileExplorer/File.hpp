#ifndef FILE_HPP
#define FILE_HPP

#include "../AButton.hpp"
#include <string>
#include "../Text.hpp"
#include "../ArrowPointer.hpp"

class File : public AButton {
public:
	File(Vec3 pos, std::string text, bool selected);
	void DrawLines(void);
	void DrawCircles(void);
	void Update(std::string text, bool visible);

private:
	Vec3 m_pos;
	bool m_visible;
	Text m_text;
	ArrowPointer m_pointer;
};

#endif // !FILE_HPP
