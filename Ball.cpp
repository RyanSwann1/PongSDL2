#include "Ball.h"
#include "CollisionManager.h"
#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include <iostream>

const std::string Ball::m_textureID = "Ball";
const std::string Ball::m_ID = "Ball";

Ball::Ball()
{
	//Initialize size
	m_sizeWidth = 30;
	m_sizeHeight = 30;

	//Initialize position
	m_position.m_x = 275;
	m_position.m_y = 225;

	//Initialize velocity
	m_velocity.m_x = -3;
	m_velocity.m_y = 0;
	m_holdBall = true; 
}


Ball::~Ball()
{

}

void Ball::update()
{
	handleEvents();

	if (m_holdBall) {
		holdingBall();
	}
	else {
		handleMovement();
	}
	
}

void Ball::draw()
{
	TextureManager::instance()->draw(m_position.m_x, m_position.m_y, m_sizeWidth, m_sizeHeight, Game::instance()->getRenderer(), "Ball");
}

void Ball::handleEvents()
{
	if (InputHandler::instance()->isKeyDown(SDL_SCANCODE_SPACE))
	{
		m_holdBall = false;
	}
}

void Ball::handleMovement()
{
	//If ball collides with game bounds
	m_velocity = checkGameBounds();

	//If ball collides with a paddle
	m_velocity = checkPaddleCollision();

	
	//Update position
	m_position += m_velocity;
}

void Ball::holdingBall()
{
	m_position.m_x = 275;
	m_position.m_y = 225;
	m_velocity.m_x = -3;
	m_velocity.m_y = 0;
}


Vector2 Ball::checkGameBounds()
{
	Vector2 newVelocity = m_velocity;
	Vector2 newPos = m_position;
	newPos += newVelocity;
	
	//IF ball collides with top and bottom walls
	if (CollisionManager::gameBoundHeight((*this), newPos))
	{
		//If ball is moving right and up
		if (m_velocity.m_x > 0 && m_velocity.m_y < 0) {
			newVelocity.m_y = 3; //Change to right and down
		}
		//If ball is moving right and down
		else if (m_velocity.m_x > 0 && m_velocity.m_y > 0) {
			newVelocity.m_y = -3;
		}
		//if ball is moving left & Up
		else if (m_velocity.m_x < 0 && m_velocity.m_y < 0) {
			newVelocity.m_y = 3;
		}
		//If ball is moving left & Down
		else if (m_velocity.m_x < 0 && m_velocity.m_y > 0) {
			newVelocity.m_y = -3;
		}
	}

	//If ball collides with left or right walls
	if (CollisionManager::gameBoundWidth((*this), newPos))
	{
		m_holdBall = true;
		Game::instance()->resetGameObjects();
	}

	return newVelocity;
}

Vector2 Ball::checkPaddleCollision()
{
	Vector2 newVelocity = m_velocity;
	//Check through gameObjects for paddle collisions
	for (auto gameObject : Game::instance()->getGameObjects())
	{
		//Test new position against paddle's
		if (CollisionManager::collisionEntity((*this), *gameObject) && gameObject->getID() == "Paddle") {
			return newVelocity = calculateHitReflection(*gameObject);
		}
	}

	return newVelocity;
}

Vector2 Ball::calculateHitReflection(const SDLGameObject& gameObject)
{
	Vector2 newVelocity = m_velocity; //New velocity when ball collides with paddle
	int ballCentre = m_position.m_y + (m_sizeHeight / 2); //Center of the ball
	int hitPos = ballCentre - gameObject.getPos().m_y; //Hit position in relation to the gameObject
	int GameObjectCentrePos = gameObject.getHeight() / 2;
	int offSet = gameObject.getHeight() / 3;

	//Keep hitPos within the bounds of the gameObject
	if (hitPos < 0) {
		hitPos = 0;
	}
	else if (hitPos > gameObject.getHeight()) {
		hitPos = gameObject.getHeight();
	}

	//If ball is moving right, reverse direction
	if (m_velocity.m_x > 0) {
		newVelocity.m_x = -3;
	}
	//IF ball is moving left, reverse direction
	else {
		newVelocity.m_x = 3;
	}

	//Hit upper region of paddle
	if (hitPos < GameObjectCentrePos - offSet) {
		newVelocity.m_y = -3;
	}
	//Hits lower region of paddle
	else if (hitPos > GameObjectCentrePos + offSet) {
		newVelocity.m_y = 3;
	}
	//Hits middle region paddle
	else {
		newVelocity.m_y = 0;
	}
	
	//std::cout << hitPos;
	//Return new velocity
	return newVelocity;
}

void Ball::reset()
{
	m_holdBall = true;
}
