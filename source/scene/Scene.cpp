#include "./Scene.hpp"

Scene::Scene(App* app) :
	m_is_popup_active(false),
	m_popup(Popup("")),
	m_app(app)
{
}

void Scene::UpdateSelected(AButton* selected) {
	m_old_selected = m_selected;
	m_selected->SetSelected(false);
	m_selected = selected;
	m_selected->SetSelected(true);
}

Scene::Type Scene::GetType() const {
	return m_type;
}

void Scene::ShowPopup(std::string text, std::string name) {
	m_is_popup_active = true;
	m_popup.Update(text, name);
	UpdateSelected(&m_popup);
}

void Scene::HidePopup() {
	m_is_popup_active = false;
	UpdateSelected(m_old_selected);
}

void Scene::DrawPopupLines() {
	if (m_is_popup_active) {
		m_popup.DrawLines();
	}
}

void Scene::DrawPopupCircles() {
	if (m_is_popup_active) {
		m_popup.DrawCircles();
	}
}

std::string Scene::GetPopupName()
{
	return m_popup.GetName();
}
