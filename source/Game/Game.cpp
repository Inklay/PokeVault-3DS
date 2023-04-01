#include "./Game.hpp"
#include "../scene/FileExplorer.hpp"
#include "../scene/BoxView.hpp"
#include "../App.hpp"
#include "../PKSM-Core/include/sav/SavDP.hpp"
#include "../PKSM-Core/include/sav/SavPT.hpp"
#include "../PKSM-Core/include/sav/SavHGSS.hpp"

Game::Game(App* app) :
	m_config(app->GetConfig()),
	m_app(app)
{
}

std::string Game::GetPlayerName() {
	return m_save_player_name;
}

std::string Game::GetTrainerId() {
	return m_save_id;
}

std::string Game::GetDexCaught() {
	return m_save_dex;
}

std::string Game::GetTimePlayed() {
	return m_save_time;
}

std::unique_ptr<pksm::Sav> const& Game::GetSave() {
	return m_save;
}

bool Game::HasSave() {
	return m_has_save;
}

std::string Game::GetName() {
	return m_name;
}

std::string Game::GetBoxArt() {
	return m_box_art;
}

std::string Game::GetLogo() {
	return m_logo;
}

pksm::GameVersion Game::GetVersion() {
	return m_game;
}

std::string Game::GetFileExtension() {
	return m_file_extension;
}

bool Game::IsCompatible(pksm::GameVersion game_version) {
	return game_version == pksm::GameVersion::Pt;
}

void Game::Unload() {
	m_data = std::make_shared<u8[]>(0);
}

void Game::OpenGame() {
	if (!m_has_save)
		m_app->ChangeScene(Scene::FILE_EXPLORER);
	else {
		LoadSave();
		m_app->ChangeScene(Scene::BOX_VIEW);
	}
}

void Game::GetBaseData() {
	LoadSave();
	m_save_player_name = m_save->otName();
	m_save_dex = std::to_string(m_save->dexCaught());
	m_save_id = std::to_string(m_save->TID());
	std::stringstream ss;
	ss << m_save->playedHours() << ":" << m_save->playedMinutes();
	m_save_time = ss.str();
	Unload();
}

void Game::LoadSave() {
	m_data = std::make_shared<u8[]>(m_size);
	std::ifstream file;
	file.open(m_config.GetKeyValue("save_location", m_save_location_config_name));
	if (file.is_open()) {
		for (int i = 0; i < m_size; i++) {
			m_data.get()[i] = file.get();
		}
		file.close();
	}
	m_save = pksm::Sav::getSave(m_data, m_size);
}
