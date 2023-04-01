#ifndef FILEEXPLORER_HPP
#define FILEEXPLORER_HPP

#include "./Scene.hpp"
#include <citro2d.h>
#include <filesystem>
#include "../UI/Header.hpp"
#include "../UI/Image.hpp"
#include "../UI/Footer.hpp"
#include "../UI/FileExplorer/File.hpp"
#include "../UI/TextBox.hpp"

class FileExplorer : public Scene {
public:
	FileExplorer(App* app);
	~FileExplorer();
	void DrawTop();
	void DrawBottom();
	void Update(u32 key_down);

private:
	TextBox m_text_box_bottom;
	std::vector<File> m_files_bottom;
	Footer m_footer_bottom;
	Footer m_footer_top;
	Image m_game_logo_top;
	Header m_header_top;
	C2D_SpriteSheet m_game_logo_sheet;
	std::string m_current_path;
	std::filesystem::directory_entry m_entry;
	size_t m_idx;
};

#endif // !FILEEXPLORER_HPP
