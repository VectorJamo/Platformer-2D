#pragma once
class Entity;
class GameObject;
class Tilemap;
struct vec2;

struct CollisionDirection
{
	bool xCollision = false, yCollision = false;
};

// Simple AABB collision
class CollisionHandler
{
public:
	static bool CheckCollision(Entity* e1, Entity* e2, const vec2& e1Vel, const vec2& e2Vel);
	static bool CheckCollision(Entity* entity, GameObject* object, const vec2& entityVel, const vec2& objectVel);
	static bool CheckCollision(GameObject* o1, GameObject* o2, const vec2& o1Vel, const vec2& o2Vel);

	static CollisionDirection CheckEntityWorldCollision(Entity* entity, Tilemap* map, const vec2& entityVel);
	static CollisionDirection CheckObjectWorldCollision(GameObject* object, Tilemap* map, const vec2& objectVel);
};