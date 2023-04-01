#ifndef GAME_HPP
#define GAME_HPP

#include "../PKSM-Core/include/sav/Sav.hpp"
#include <string>
#include <memory>
#include <fstream>
#include <sstream>
#include "../Config/Config.hpp"

class App;

class Game {
public:
	Game(App* app);
	virtual ~Game() {};
	static bool IsCompatible(pksm::GameVersion game_version);
	bool HasSave();
	std::string GetName();
	std::string GetBoxArt();
	std::string GetLogo();
	pksm::GameVersion GetVersion();
	virtual void SetSave(std::string path) = 0;
	std::string GetFileExtension();
	std::string GetPlayerName();
	std::string GetTrainerId();
	std::string GetDexCaught();
	std::string GetTimePlayed();
	std::unique_ptr<pksm::Sav> const& GetSave();
	void Unload();
	void OpenGame();
	void GetBaseData();
	void LoadSave();

	std::unique_ptr<pksm::Sav> m_save;

protected:
	Config m_config;
	std::string m_save_player_name;
	std::string m_save_dex;
	std::string m_save_id;
	std::string m_save_time;
	size_t m_size;
	std::shared_ptr<u8[]> m_data;
	App* m_app;
	bool m_is_init;
	pksm::GameVersion m_game;
	bool m_has_save;
	std::string m_name;
	std::string m_box_art;
	std::string m_logo;
	std::string m_file_extension;
	std::string m_save_location_config_name;
};

#endif // !GAME_HPP
