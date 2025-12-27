#pragma once
#include <iostream>

#include <src/states/StateManager.h>

#include <src/input/KeyManager.h>
#include <src/input/MouseManager.h>
#include <src/ui/UIManager.h>

#include <src/utils/Texture.h>

#include <src/map/Tilemap.h>

#include <src/layers/EntityLayer.h>

class GameState : public StateManager
{
private:
	// Map
	SpriteSheet* m_WorldSheet;
	Tilemap* m_Map;

	// Entities
	EntityLayer* m_EntityLayer;

public:
	GameState(Window* window, bool* isAppRunning);
	~GameState();

	void Init() override;
	void Update() override;
	void Render() override;

	void LoadAssets();
};