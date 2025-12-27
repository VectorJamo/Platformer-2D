#pragma once

#include <SDL.h>

// Like a cutscene
class Scene
{
protected:
	int m_CurrentFrame;
	bool m_HasSceneFinished;
	bool m_IsScenePlaying;

	static SDL_Renderer* m_Renderer;

public:
	static Scene* ActiveScene;

public:
	Scene(SDL_Renderer* renderer);

	virtual void Update() = 0;
	virtual void Render() = 0;

	void PlayScene();
	void EndScene();

	inline bool HasSceneFinished() { return m_HasSceneFinished; }
};

