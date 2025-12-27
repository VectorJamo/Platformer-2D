#pragma once
#include "Window.h"

class Application
{
private:
	Window* m_Window;
	bool m_Running;

	unsigned long long m_LastTime;
	static double m_DeltaTime;

	// For FPS logging
	static double m_Frequency;
	static constexpr float m_FPSLogFrequency = 1.0f;
	static double m_TimePassed; 	

private:
	void LogFPS();

public:
	Application(int width, int height, const char* title);
	~Application();

	void Run();

	inline static double GetDeltaTime() { return m_DeltaTime; }
};
