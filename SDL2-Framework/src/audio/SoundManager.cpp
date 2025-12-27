#include "SoundManager.h"
#include <iostream>

#define FREQUENCY 44100
#define NUM_CHANNELS 2
#define CHUNK_SIZE 2048

bool SoundManager::InitializeAudio()
{
	if (Mix_OpenAudio(FREQUENCY, MIX_DEFAULT_FORMAT, NUM_CHANNELS, CHUNK_SIZE) != 0)
	{
		std::cout << SDL_GetError() << std::endl;
		return false;
	}
	return true;
}
