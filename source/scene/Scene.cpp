#include "./Scene.hpp"

void Scene::update_selected(std::shared_ptr<AButton> selected) {
	m_old_selected = m_selected;
	m_selected->set_selected(false);
	m_selected = selected;
	m_selected->set_selected(true);
}

std::string Scene::get_name(void) {
	return m_name;
}
