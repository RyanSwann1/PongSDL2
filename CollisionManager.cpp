#include "CollisionManager.h"
#include "Vector2.h"
#include "Game.h"

CollisionManager::CollisionManager()
{
}


CollisionManager::~CollisionManager()
{
}

bool CollisionManager::gameBoundWidth(const SDLGameObject & gameObject, const Vector2 & newPos)
{
	if (newPos.m_x >= 0 && newPos.m_x + gameObject.getWidth() <= Game::instance()->getPlayingFieldWidth()) {
		return false;
	}
	return true;
}

bool CollisionManager::gameBoundHeight(const SDLGameObject & gameObject, const Vector2 & newPos)
{
	if (newPos.m_y >= 0 && newPos.m_y + gameObject.getHeight() <= Game::instance()->getPlayingFieldHeight()) {
		return false;
	}
	return true;
}




bool CollisionManager::gameBounds(const SDLGameObject & gameObject, const Vector2& newPos)
{
	//Game boundaries
	const unsigned int gameWidth = Game::instance()->getPlayingFieldWidth();
	const unsigned int gameHeight = Game::instance()->getPlayingFieldHeight();

	if (newPos.m_x >= 0 && (newPos.m_x + gameObject.getWidth()) <= gameWidth && newPos.m_y >= 0 && (newPos.m_y + gameObject.getHeight()) <= gameHeight) {
		return false;
	}

	return true;
}

bool CollisionManager::collisionEntity(const SDLGameObject& entity1, const SDLGameObject& entity2)
{
	if (entity1.getPos().m_x + entity1.getWidth() > entity2.getPos().m_x && entity1.getPos().m_x < entity2.getPos().m_x + entity2.getWidth() &&
		entity1.getPos().m_y + entity1.getHeight() > entity2.getPos().m_y && entity1.getPos().m_y < entity2.getPos().m_y + entity2.getHeight()) {
		return true;
	}
	return false;
}
