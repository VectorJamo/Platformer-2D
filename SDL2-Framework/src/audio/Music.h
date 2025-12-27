#pragma once
#include "SoundManager.h"

class Music
{
private:
	Mix_Music* m_Music;

public:
	Music(const char* path);
	~Music();

	void Play(int loops);
	void Pause();
	void Resume();
	void Stop();

	void SetVolume(float percentage);
};

