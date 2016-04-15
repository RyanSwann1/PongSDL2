#include "Player.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "Game.h"
#include "CollisionManager.h"
#include <iostream>

const std::string Player::m_textureID = "Player";
const std::string Player::m_ID = "Paddle";

Player::Player()
{
	//Initialize size
	m_sizeHeight = 80;
	m_sizeWidth = 25;

	//Initialize starting position
	m_position.setX(50);
	m_position.setY(200);

	//Initialize velocity
	m_velocity.setX(0);
	m_velocity.setY(3);
}


Player::~Player()
{
}

void Player::update()
{
	handleEvents();
}

void Player::draw()
{
	TextureManager::instance()->draw(m_position.getX(), m_position.getY(), m_sizeWidth, m_sizeHeight, Game::instance()->getRenderer(), m_textureID);
}

void Player::handleEvents()
{
	//New values
	Vector2 newVelocity = m_velocity;
	Vector2 newPos = m_position;
	//If Up key is pressed
	if (InputHandler::instance()->isKeyDown(SDL_SCANCODE_W))
	{	
		//Get position of requested movement
		newVelocity.m_y = -3;
		newPos += newVelocity;
		//Check requested movement is within bounds
		if (!CollisionManager::gameBounds((*this), newPos)) {
			//Allow new velocity
			m_velocity = newVelocity;
		}
		//If new position is colison, dont allow
		else
		{
			m_velocity.m_y = 0;
		}
		//Change position
		m_position += m_velocity;
	}

	//If Down key is pressed
	else if (InputHandler::instance()->isKeyDown(SDL_SCANCODE_S)) 
	{
		//Get position of requested movement
		newVelocity.m_y = 3;
		newPos += newVelocity;
		//Check requested position is within bounds
		if (!CollisionManager::gameBounds((*this), newPos)) {
			//Alow new velocity
			m_velocity = newVelocity;
		}
		//If next position is collision, dont allow
		else
		{
			m_velocity.m_y = 0;
		}
		//Update position
		m_position += m_velocity;
	}
}

void Player::reset()
{
	//Initialize starting position
	m_position.setX(50);
	m_position.setY(200);

	//Initialize velocity
	m_velocity.setX(0);
	m_velocity.setY(3);
}

std::string Player::getTextureID() const
{
	return m_textureID;
}

std::string Player::getID() const
{
	return m_ID;
}
