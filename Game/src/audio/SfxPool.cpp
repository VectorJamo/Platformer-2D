#include "SfxPool.h"

SoundEffect* SfxPool::coinSfx;
SoundEffect* SfxPool::jumpSfx;
SoundEffect* SfxPool::hurtSfx;

void SfxPool::InitializeSfx()
{
	coinSfx = new SoundEffect("res/audio/sfx/pickupCoin.wav");
	jumpSfx = new SoundEffect("res/audio/sfx/jump.wav");
	hurtSfx = new SoundEffect("res/audio/sfx/hitHurt.wav");

	coinSfx->SetVolume(0.25f);
	jumpSfx->SetVolume(0.05f);
	hurtSfx->SetVolume(0.75f);
}
