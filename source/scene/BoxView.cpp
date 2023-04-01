#include "./BoxView.hpp"
#include "../scene/GameSelect.hpp"
#include "../utils/SpriteSheet.hpp"
#include <sstream>
#include "../App.hpp"

BoxView::BoxView(App* app) :
	m_current_box(app->GetSelectedGame()->GetSave()->currentBox()),
	m_box_bottom(Box(false, GFX_BOTTOM, app->GetSelectedGame()->GetSave())),
	m_box_top(Box(true, GFX_TOP, app->GetSelectedGame()->GetSave())),
	Scene(app)
{
	m_type = BOX_VIEW;
	m_viewing_top = true;
}

void BoxView::DrawTop() {
	// Lines
	m_box_top.DrawLines();

	// Circles
	m_box_top.DrawCircles();
}

void BoxView::DrawBottom() {
	// Lines
	m_box_bottom.DrawLines();

	// Circles
	m_box_bottom.DrawCircles();
}

void BoxView::Update(u32 key_down) {
	if (key_down & KEY_START) {
		m_app->ChangeScene(GAME_SELECT);
		return;
	} else if (key_down & KEY_L) {
		if (m_viewing_top) {
			m_current_box++;
			if (m_current_box == m_app->GetSelectedGame()->GetSave()->maxBoxes()) {
				m_current_box = 0;
			}
			m_app->GetSelectedGame()->GetSave()->currentBox(m_current_box);
			m_box_top.Update(true);
		} else {
			if (m_current_box == m_app->GetSelectedGame()->GetSave()->maxBoxes()) {
				m_current_box = 0;
			}
			m_app->GetSelectedGame()->GetSave()->currentBox(m_current_box);
			m_box_bottom.Update(true);
		}
	} else if (key_down & KEY_R) {
		m_current_box--;
		if (m_viewing_top) {
			if (m_current_box == -1) {
				m_current_box = m_app->GetSelectedGame()->GetSave()->maxBoxes() - 1;
			}
			m_app->GetSelectedGame()->GetSave()->currentBox(m_current_box);
			m_box_top.Update(true);
		}
		else {
			if (m_current_box == -1) {
				m_current_box = m_app->GetSelectedGame()->GetSave()->maxBoxes() - 1;
			}
			m_app->GetSelectedGame()->GetSave()->currentBox(m_current_box);
			m_box_bottom.Update(true);
		}
	}
}
