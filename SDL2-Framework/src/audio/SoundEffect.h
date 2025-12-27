#pragma once
#include "SoundManager.h"

class SoundEffect
{
private:
	Mix_Chunk* m_Sfx;

public:
	SoundEffect(const char* path);
	~SoundEffect();

	void Play();
	void PlayLooped(int loops);
	void SetVolume(float percentage);
};

