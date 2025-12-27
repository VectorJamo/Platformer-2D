#include "Music.h"
#include <iostream>

Music::Music(const char* path)
	:m_Music(nullptr)
{
	m_Music = Mix_LoadMUS(path);
	if (m_Music == nullptr)
	{
		std::cout << "Failed to load music!" << std::endl;
	}
}

Music::~Music()
{
	Mix_FreeMusic(m_Music);
}

void Music::Play(int loops)
{
	if (Mix_PlayingMusic() == 0)
	{
		Mix_PlayMusic(m_Music, loops);
	}
}

void Music::Pause()
{
	if (Mix_PausedMusic() == 0)
	{
		Mix_PauseMusic();
	}
}

void Music::Resume()
{
	if (Mix_PausedMusic() == 1)
	{
		Mix_ResumeMusic();
	}
}

void Music::Stop()
{
	if (Mix_PlayingMusic() || Mix_PausedMusic())
	{
		Mix_HaltMusic();
	}
}

void Music::SetVolume(float percentage)
{
	Mix_VolumeMusic(MIX_MAX_VOLUME * percentage);
}
