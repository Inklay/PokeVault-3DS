#ifndef POPUP_HPP
#define POPUP_HPP

#include "./AButton.hpp"
#include "./Text.hpp"
#include "./Button.hpp"

class Popup : public AButton {
public:
	Popup(std::string text, std::string name = "");
	void draw_lines(void);
	void draw_circles(void);
	std::string name;

private:
	Text m_text;
	Button m_button;
};


#endif // !POPUP_HPP