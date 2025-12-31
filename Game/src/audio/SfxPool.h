#pragma once
#include "src/audio/SoundEffect.h"

struct SfxPool
{
	static SoundEffect* coinSfx, * jumpSfx;
	
	static void InitializeSfx();
};

