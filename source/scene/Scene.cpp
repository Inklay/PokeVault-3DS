#include "./Scene.hpp"

void Scene::update_selected(std::shared_ptr<AButton> selected) {
	m_selected->set_selected(false);
	m_selected = selected;
	m_selected->set_selected(true);
}
