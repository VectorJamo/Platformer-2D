#include "SoundEffect.h"
#include <iostream>

SoundEffect::SoundEffect(const char* path)
	:m_Sfx(nullptr)
{
	m_Sfx = Mix_LoadWAV(path);
	if (m_Sfx == nullptr)
	{
		std::cout << "Cannot load sound effect." << std::endl;
	}
}

SoundEffect::~SoundEffect()
{
	Mix_FreeChunk(m_Sfx);
}

void SoundEffect::Play()
{
	Mix_PlayChannel(-1, m_Sfx, 0);
}

void SoundEffect::PlayLooped(int loops)
{
	Mix_PlayChannel(-1, m_Sfx, loops);
}

void SoundEffect::SetVolume(float percentage)
{
	Mix_VolumeChunk(m_Sfx, MIX_MAX_VOLUME * percentage);
}
