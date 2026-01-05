#pragma once
#include <iostream>

#include <src/states/StateManager.h>

#include <src/input/KeyManager.h>
#include <src/input/MouseManager.h>
#include <src/ui/UIManager.h>

#include <src/utils/Texture.h>

#include <src/map/Tilemap.h>

#include <src/layers/EntityLayer.h>
#include "src/layers/MapLayer.h"
#include "src/layers/ObjectLayer.h"
#include "src/layers/UILayer.h"
#include "src/audio/Music.h"

class GameState : public StateManager
{
private:
	// Map
	MapLayer* m_MapLayer;

	// Entities
	EntityLayer* m_EntityLayer;

	// Objects
	ObjectLayer* m_ObjectLayer;

	// UI Layer
	UILayer* m_UILayer;

	// Music
	Music* m_BackgroundMusic;

public:
	GameState(Window* window, bool* isAppRunning);
	~GameState();

	void Init() override;
	void Update() override;
	void Render() override;

	void HandleStateChanges();
};