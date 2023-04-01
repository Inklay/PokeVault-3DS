#include "App.hpp"
#include "Scene/GameSelect.hpp"
#include "Scene/FileExplorer.hpp"
#include "Scene/BoxView.hpp"

App::App() {
	m_top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	m_bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);
	m_color_clear = C2D_Color32(0x00, 0x00, 0x00, 0x00);
	srand(time(NULL));
	m_hold_timer = 0;
	m_hold_threshold = 20;
	m_game_index = 0;
	

	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	cfguInit();
	romfsInit();
}

App::~App() {
	romfsExit();
	cfguExit();
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	delete m_scene;
	for (Game* g : m_games) {
		delete g;
	}
}

void App::Init() {
	CreateGameVector();
	m_scene = new GameSelect(this);
}

void App::CreateGameVector() {
	m_games.emplace_back(new Diamond(this));
	m_games.emplace_back(new Pearl(this));
	m_games.emplace_back(new Platinum(this));
	m_games.emplace_back(new HeartGold(this));
	m_games.emplace_back(new SoulSilver(this));
}

void App::Run() {
	while (aptMainLoop()) {
		HandleInput();
		if (m_key_down & KEY_START && m_scene->GetType() == Scene::GAME_SELECT) {
			break;
		}

		m_scene->Update(m_key_down);
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);

		C2D_TargetClear(m_top, m_color_clear);
		C2D_SceneBegin(m_top);
		m_background.DrawTop();
		m_scene->DrawTop();

		
		C2D_TargetClear(m_bottom, m_color_clear);
		C2D_SceneBegin(m_bottom);
		m_background.DrawBottom();
		m_scene->DrawBottom();

		C3D_FrameEnd(0);
	}
}

Config App::GetConfig() const {
	return m_config;
}

Game* App::GetSelectedGame() {
	return m_games.at(m_game_index);
}

void App::SetGameIndex(uint32_t game_index) {
	m_game_index = game_index;
}

std::vector<Game*> App::GetGames() {
	return m_games;
}

void App::HandleInput() {
	hidScanInput();
	m_key_down = hidKeysDown();
	u32 key_held = hidKeysHeld();

	if (m_hold_timer == m_hold_threshold) {
		m_key_down = m_key_down | key_held;
		m_hold_timer = 0;
		if (m_hold_threshold != 10) {
			m_hold_threshold = 10;
		}
	}

#ifdef _DEBUG
	if (m_key_down & KEY_L && m_key_down & KEY_R) {
		m_config.SetKeyValue("save_location", "platinum", "none");
	}
#endif

	if (key_held != 0)
		m_hold_timer++;
	else if (m_hold_timer != 0) {
		m_hold_timer = 0;
		m_hold_threshold = 20;
	}
}

void App::ChangeScene(Scene::Type scene) {
	delete m_scene;
	switch (scene) {
		case Scene::GAME_SELECT:
			m_scene = new GameSelect(this);
			return;
		case Scene::FILE_EXPLORER:
			m_scene = new FileExplorer(this);
			return;
		case Scene::BOX_VIEW:
			m_scene = new BoxView(this);
			return;
	}
}
