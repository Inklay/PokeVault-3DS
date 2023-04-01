#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <memory>
#include "../UI/AButton.hpp"
#include <string>
#include "../UI/Popup.hpp"

class App;

class Scene {
public:
	enum Type {
		GAME_SELECT,
		FILE_EXPLORER,
		BOX_VIEW
	};

	Scene(App* app);
	virtual ~Scene() {};
	virtual void DrawTop() = 0;
	virtual void DrawBottom() = 0;
	virtual void Update(u32 key_down) = 0;
	void UpdateSelected(AButton* selected);
	Type GetType() const;
	void ShowPopup(std::string text, std::string name);
	void HidePopup();
	void DrawPopupLines();
	void DrawPopupCircles();
	std::string GetPopupName();

protected:
	App* m_app;
	Popup m_popup;
	bool m_is_popup_active;
	Type m_type;
	AButton* m_selected;
	AButton* m_old_selected;
};

#endif // !SCENE_HPP
