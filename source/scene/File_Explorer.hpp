#ifndef FILE_EXPLORER_HPP
#define FILE_EXPLORER_HPP

#include "./Scene.hpp"

class File_Explorer : public Scene {
public:
	void load(std::vector<std::shared_ptr<UI_Element>>& top_elem,
		std::vector<std::shared_ptr<UI_Element>>& bottom_elem);
	void unload(void);
	void update_inputs(u32 key_down);
};

#endif // !FILE_EXPLORER_HPP
