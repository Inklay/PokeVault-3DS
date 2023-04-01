#ifndef APP_HPP
#define APP_HPP

#include <3ds.h>
#include <time.h>
#include <citro2d.h>
#include <time.h>
#include "Config/Config.hpp"
#include "Scene/Background/Background.hpp"
#include "Scene/Scene.hpp"
#include "Game/all.hpp"

class App {
public:
	App();
	~App();
	void Init();
	void ChangeScene(Scene::Type);
	void Run();
	Config GetConfig() const;
	std::vector<Game*> GetGames();
	Game* GetSelectedGame();
	void SetGameIndex(uint32_t game_index);

private:
	void HandleInput();
	void CreateGameVector();

	u32 m_key_down;
	C3D_RenderTarget* m_top;
	C3D_RenderTarget* m_bottom;
	u32 m_color_clear;
	Scene* m_scene;
	uint32_t m_hold_timer;
	uint32_t m_hold_threshold;
	Config m_config;
	Background m_background;
	std::vector<Game*> m_games;
	uint32_t m_game_index;
};

#endif // !APP_HPP
