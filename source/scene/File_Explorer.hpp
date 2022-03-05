#ifndef FILE_EXPLORER_HPP
#define FILE_EXPLORER_HPP

#include "./Scene.hpp"
#include <citro2d.h>

class File_Explorer : public Scene {
public:
	void load(std::vector<std::shared_ptr<UI_Element>>& top_elem,
		std::vector<std::shared_ptr<UI_Element>>& bottom_elem);
	void unload(void);
	void update_inputs(u32 key_down);

private:
	C2D_SpriteSheet m_game_logo_sheet;
};

#endif // !FILE_EXPLORER_HPP
