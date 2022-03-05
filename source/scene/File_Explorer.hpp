#ifndef FILE_EXPLORER_HPP
#define FILE_EXPLORER_HPP

#include "./Scene.hpp"
#include <citro2d.h>
#include <filesystem>

class File_Explorer : public Scene {
public:
	void load(std::vector<std::shared_ptr<UI_Element>>& top_elem,
		std::vector<std::shared_ptr<UI_Element>>& bottom_elem);
	void unload(void);
	void update(std::vector<std::shared_ptr<UI_Element>>& top_elem,
		std::vector<std::shared_ptr<UI_Element>>& bottom_elem, u32 key_down);

private:
	C2D_SpriteSheet m_game_logo_sheet;
	std::string m_current_path;
	std::filesystem::directory_entry m_selected;
	size_t m_idx;
};

#endif // !FILE_EXPLORER_HPP
