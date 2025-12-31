#include "SfxPool.h"

SoundEffect* SfxPool::coinSfx;
SoundEffect* SfxPool::jumpSfx;

void SfxPool::InitializeSfx()
{
	coinSfx = new SoundEffect("res/audio/sfx/pickupCoin.wav");
	jumpSfx = new SoundEffect("res/audio/sfx/jump.wav");
}
