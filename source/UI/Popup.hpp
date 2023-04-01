#ifndef POPUP_HPP
#define POPUP_HPP

#include "./AButton.hpp"
#include "./Text.hpp"
#include "./Button.hpp"

class Popup : public AButton {
public:
	Popup(std::string text);
	void DrawLines();
	void DrawCircles();
	void Update(std::string text, std::string name);
	std::string GetName();

private:
	std::string m_name;
	Text m_text;
	Button m_button;
};


#endif // !POPUP_HPP