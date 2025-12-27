#include "Scene.h"

Scene* Scene::ActiveScene = nullptr;
SDL_Renderer* Scene::m_Renderer = nullptr;

Scene::Scene(SDL_Renderer* renderer)
{
	m_Renderer = renderer;

	m_HasSceneFinished = false;
	m_IsScenePlaying = false;
	m_CurrentFrame = 0;
}

void Scene::PlayScene()
{
	ActiveScene = this;
}

void Scene::EndScene()
{
	m_HasSceneFinished = true;
	m_IsScenePlaying = false;

	ActiveScene = nullptr;
}
