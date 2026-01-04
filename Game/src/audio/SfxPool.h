#pragma once
#include "src/audio/SoundEffect.h"

struct SfxPool
{
	static SoundEffect* coinSfx, * jumpSfx, *hurtSfx;
	
	static void InitializeSfx();
};

