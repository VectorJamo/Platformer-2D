#include "Player.h"

Player::Player(int playerID, const char* playerSpritePath)
	:Entity(playerID, playerSpritePath)
{
}

Player::~Player()
{
}

void Player::Update()
{
}

void Player::Render(SDL_Renderer* renderer)
{
}

void Player::Render(SDL_Renderer* renderer, float camX, float camY)
{
}