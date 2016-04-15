#include "Opponent.h"
#include "TextureManager.h"
#include "Game.h"
#include "CollisionManager.h"
#include "Player.h"
#include <iostream>
#include <string>

const std::string Opponent::m_textureID = "Opponent";
const std::string Opponent::m_ID = "Paddle";

Opponent::Opponent()
{
	//Initialize size
	m_sizeHeight = 80;
	m_sizeWidth = 25;

	//Initialize Starting position
	m_position.setX(650);
	m_position.setY(200);

	//Initialize velocity
	m_velocity.setX(0);
 	m_velocity.setY(2.5f);
}


Opponent::~Opponent()
{
}

void Opponent::update()
{
	
	handleMovement();

	
}

void Opponent::draw()
{
	TextureManager::instance()->draw(m_position.m_x, m_position.m_y, m_sizeWidth, m_sizeHeight, Game::instance()->getRenderer(), m_textureID);
}

void Opponent::handleEvents()
{
}

void Opponent::handleMovement()
{
	int centrePos = m_position.m_y + (m_sizeHeight / 2);
	Vector2 newVelocity = m_velocity;
	Vector2 newPos = m_position;

	for (auto &gameObject : Game::instance()->getGameObjects())
	{
		//Get the ball game object
		if (gameObject->getID() == "Ball")
		{
			//If ball is on the opponents side of the playing field
			if (gameObject->getPos().m_x >= Game::instance()->getPlayingFieldWidth() / 2)
			{
				//If ball is higher than opponent center position
				if (gameObject->getPos().m_y + (gameObject->getHeight() / 2) < centrePos)
				{
					//GEt position of requested movement
					newVelocity.m_y = -2.5f;
					newPos += newVelocity;
					//Test new position of movement for collision
					if (!CollisionManager::gameBounds((*this), newPos)) {
						m_velocity = newVelocity; //If no collision on new position, accept position
					}
					else
					{
						m_velocity.m_y = 0;
					}
				}

				if (gameObject->getPos().m_y + (gameObject->getHeight() / 2) > centrePos)
				{
					//Get position of requested movement
					newVelocity.m_y = 2.5f;
					newPos+= newVelocity;
					//Test position of new movement for collision
					if (!CollisionManager::gameBounds((*this), newPos)) {
						m_velocity = newVelocity; //If no collision on new position, accept position
					}
					else
					{
						m_velocity.m_y = 0;
					}
				}
				m_position += m_velocity;
			}
		}
	}
}

std::string Opponent::getTextureID() const
{
	return m_textureID;
}

std::string Opponent::getID() const
{
	return m_ID;
}

void Opponent::reset()
{
	//Initialize Starting position
	m_position.setX(650);
	m_position.setY(200);

	//Initialize velocity
	m_velocity.setX(0);
	m_velocity.setY(2.5f);
}
