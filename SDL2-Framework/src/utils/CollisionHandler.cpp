#include "CollisionHandler.h"

#include "entities/Entity.h"
#include "objects/GameObject.h"

#include "map/MapConstants.h"
#include "map/Tilemap.h"

#include <cmath>
#include <iostream>

bool CollisionHandler::CheckCollision(Entity* e1, Entity* e2, const vec2& e1Vel, const vec2& e2Vel)
{
    float e1XNew = e1->GetPosition().x + e1Vel.x;
	float e1YNew = e1->GetPosition().y + e1Vel.y;
	float e2XNew = e2->GetPosition().x + e2Vel.x;
	float e2YNew = e2->GetPosition().y + e2Vel.y;

	if (e1XNew > e2XNew + e2->GetDimension().x || e1YNew > e2YNew + e2->GetDimension().y
		|| e2XNew > e1XNew + e1->GetDimension().x || e2YNew > e1YNew + e1->GetDimension().y)
	{
		return false;
	}
    return true;
}

bool CollisionHandler::CheckCollision(Entity* entity, GameObject* object, const vec2& entityVel, const vec2& objectVel)
{
	float entityXNew = entity->GetPosition().x + entity->GetCollisionRect().x + entityVel.x;
	float entityYNew = entity->GetPosition().y + entity->GetCollisionRect().y + entityVel.y;
	float objectXNew = object->GetPosition().x + objectVel.x;
	float objectYNew = object->GetPosition().y + objectVel.y;

	if (entityXNew > objectXNew + object->GetDimension().x || entityYNew > objectYNew + object->GetDimension().y
		|| objectXNew > entityXNew + entity->GetCollisionRect().w || objectYNew > entityYNew + entity->GetCollisionRect().h)
	{
		return false;
	}
	return true;
}

CollisionDirection CollisionHandler::CheckCollisionWithDirection(Entity* entity, GameObject* object, const vec2& entityVel, const vec2& objectVel)
{
	CollisionDirection collisionDirection;

	if (entityVel.x != 0.0f || objectVel.x != 0.0f)
	{
		// Check for x-axis collision
		float entityXNew = entity->GetPosition().x + entity->GetCollisionRect().x + entityVel.x;
		float entityYNew = entity->GetPosition().y + entity->GetCollisionRect().y;
		float objectXNew = object->GetPosition().x + objectVel.x;
		float objectYNew = object->GetPosition().y + objectVel.y;

		if (entityXNew > objectXNew + object->GetDimension().width || entityYNew > objectYNew + object->GetDimension().y
			|| objectXNew > entityXNew + entity->GetCollisionRect().w || objectYNew > entityYNew + entity->GetCollisionRect().h)
		{
			collisionDirection.xCollision = false;
		}
		else {
			collisionDirection.xCollision = true;
		}
	}
	if (entityVel.y != 0.0f || objectVel.y != 0.0f)
	{
		// Check for y-axis collision
		float entityXNew = entity->GetPosition().x + entity->GetCollisionRect().x;
		float entityYNew = entity->GetPosition().y + entity->GetCollisionRect().y + entityVel.y;
		float objectXNew = object->GetPosition().x + objectVel.x;
		float objectYNew = object->GetPosition().y + objectVel.y;

		if (entityXNew > objectXNew + object->GetDimension().width || entityYNew > objectYNew + object->GetDimension().y
			|| objectXNew > entityXNew + entity->GetCollisionRect().w || objectYNew > entityYNew + entity->GetCollisionRect().h)
		{
			collisionDirection.yCollision = false;
		}
		else {
			collisionDirection.yCollision = true;
		}
	}

	return collisionDirection;
}

bool CollisionHandler::CheckCollision(GameObject* o1, GameObject* o2, const vec2& o1Vel, const vec2& o2Vel)
{
	float o1XNew = o1->GetPosition().x + o1Vel.x;
	float o1YNew = o1->GetPosition().y + o1Vel.y;
	float o2XNew = o2->GetPosition().x + o2Vel.x;
	float o2YNew = o2->GetPosition().y + o2Vel.y;

	if (o1XNew > o2XNew + o2->GetDimension().x || o1YNew > o2YNew + o2->GetDimension().y
		|| o2XNew > o1XNew + o1->GetDimension().x || o2YNew > o1YNew + o1->GetDimension().y)
	{
		return false;
	}
	return true;
}

CollisionDirection CollisionHandler::CheckEntityWorldCollision(Entity* entity, Tilemap* map, const vec2& entityVel)
{
	CollisionDirection direction;
	// For x-direction
	if (entityVel.x > 0)
	{
		// Right direction
		int topRightRow, topRightCol, bottomRightRow, bottomRightCol;

		topRightRow = (entity->GetPosition().y + entity->GetCollisionRect().y) / MapConstants::TileHeight;
		topRightCol = (entity->GetPosition().x + entity->GetCollisionRect().x + entity->GetCollisionRect().w + entityVel.x ) / MapConstants::TileWidth;
		bottomRightRow = (entity->GetPosition().y + entity->GetCollisionRect().y + entity->GetCollisionRect().h) / MapConstants::TileHeight;
		bottomRightCol = (entity->GetPosition().x + entity->GetCollisionRect().x + entity->GetCollisionRect().w + entityVel.x) / MapConstants::TileWidth;

		bool topRightCollision = (map->GetMap()[topRightRow][topRightCol] != 0);
		bool bottomRightCollision = (map->GetMap()[bottomRightRow][bottomRightCol] != 0);

		direction.xCollision = (topRightCollision || bottomRightCollision);
	}
	else {
		// Left direction
		int topLeftRow, topLeftCol, bottomLeftRow, bottomLeftCol;
		topLeftRow = (entity->GetPosition().y + entity->GetCollisionRect().y) / MapConstants::TileHeight;
		topLeftCol = (entity->GetPosition().x + entity->GetCollisionRect().x + entityVel.x) / MapConstants::TileWidth;
		bottomLeftRow = (entity->GetPosition().y + entity->GetCollisionRect().y + entity->GetCollisionRect().h) / MapConstants::TileHeight;
		bottomLeftCol = (entity->GetPosition().x + entity->GetCollisionRect().x + entityVel.x) / MapConstants::TileWidth;

		bool topLeftCollision = (map->GetMap()[topLeftRow][topLeftCol] != 0);
		bool bottomLeftCollision = (map->GetMap()[bottomLeftRow][bottomLeftCol] != 0);

		direction.xCollision = (topLeftCollision || bottomLeftCollision);
	}

	// For y-direction
	if (entityVel.y < 0)
	{
		// Up direction
		int topLeftRow, topLeftCol, topRightRow, topRightCol;

		topLeftRow = (entity->GetPosition().y + entity->GetCollisionRect().y + entityVel.y) / MapConstants::TileHeight;
		topLeftCol = (entity->GetPosition().x + entity->GetCollisionRect().x) / MapConstants::TileWidth;
		topRightRow = (entity->GetPosition().y + entity->GetCollisionRect().y + entityVel.y) / MapConstants::TileHeight;
		topRightCol = (entity->GetPosition().x + entity->GetCollisionRect().x + entity->GetCollisionRect().w) / MapConstants::TileWidth;

		bool topLeftCollision = (map->GetMap()[topLeftRow][topLeftCol] != 0);
		bool topRightCollision = (map->GetMap()[topRightRow][topRightCol] != 0);

		direction.yCollision = (topLeftCollision || topRightCollision);
	}
	else {
		// Down direction
		int bottomLeftRow, bottomLeftCol, bottomRightRow, bottomRightCol;

		bottomLeftRow = (entity->GetPosition().y + entity->GetCollisionRect().y + entity->GetCollisionRect().h + entityVel.y) / MapConstants::TileHeight;
		bottomLeftCol = (entity->GetPosition().x + entity->GetCollisionRect().x) / MapConstants::TileWidth;
		bottomRightRow = (entity->GetPosition().y + entity->GetCollisionRect().y + entity->GetCollisionRect().h + entityVel.y) / MapConstants::TileHeight;
		bottomRightCol = (entity->GetPosition().x + entity->GetCollisionRect().x + entity->GetCollisionRect().w) / MapConstants::TileWidth;

		bool bottomLeftCollision = (map->GetMap()[bottomLeftRow][bottomLeftCol] != 0);
		bool bottomRightCollision = (map->GetMap()[bottomRightRow][bottomRightCol] != 0);

		direction.yCollision = (bottomLeftCollision || bottomRightCollision);
	}

	return direction;
}

CollisionDirection CollisionHandler::CheckObjectWorldCollision(GameObject* object, Tilemap* map, const vec2& objectVel)
{
	CollisionDirection direction;


	return direction;
}
