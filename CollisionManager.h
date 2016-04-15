#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include "SDLGameObject.h"

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	static bool gameBoundWidth(const SDLGameObject& gameObject, const Vector2& newPos);
	static bool gameBoundHeight(const SDLGameObject& gameObject, const Vector2& newPos);
	static bool gameBounds(const SDLGameObject& pos, const Vector2& newPos);
	static bool collisionEntity(const SDLGameObject& entity1, const SDLGameObject& entity2);

private:

};
#endif // !COLLISION_MANAGER_H
