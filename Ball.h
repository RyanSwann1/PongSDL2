#ifndef BALL_H
#define BALL_H


#include "SDLGameObject.h"
#include "Vector2.h"
#include "MoveDirection.h"

class Ball :
	public SDLGameObject
{
public:
	Ball();
	~Ball();

	void update() override;
	void draw() override;
	void handleEvents() override;
	std::string getTextureID() const override { return m_textureID; }
	std::string getID() const override { return m_ID; }
	Vector2 getPos() const override { return m_position; }
	int getWidth() const override { return m_sizeWidth; }
	int getHeight() const override { return m_sizeHeight; }
	void reset() override;
	
	void handleMovement();
	void holdingBall();
	Vector2 checkGameBounds();
	Vector2 checkPaddleCollision();
	Vector2 calculateHitReflection(const SDLGameObject& paddle);
	
		
	//virtual void update() = 0;
	//virtual void draw() = 0;
	//virtual void handleEvents() = 0;
	//virtual std::string getTextureID() const = 0;
	//virtual std::string getID() const = 0;
	//virtual Vector2 getPos() const = 0;

private:
	int m_sizeWidth;
	int m_sizeHeight;
	bool m_holdBall;

	Vector2 m_position;
	Vector2 m_velocity;
	static const std::string m_textureID;
	static const std::string m_ID;
}; 
#endif // !BALL_H

