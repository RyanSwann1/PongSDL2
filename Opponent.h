#ifndef OPPONENT_H
#define OPPONENT_H

#include "SDLGameObject.h"
#include "Vector2.h"
#include <string>
class Opponent :
	public SDLGameObject
{
public:
	Opponent();
	~Opponent();

	void update() override;
	void draw() override;
	void handleEvents() override;
	void handleMovement();
	void reset() override;
	int getWidth() const override { return m_sizeWidth; }
	int getHeight() const override { return m_sizeHeight; }
	std::string getID() const override;
	Vector2 getPos() const override { return m_position; }
	
	
	
	std::string getTextureID() const;


private:
	Vector2 m_position;
	Vector2 m_velocity;
	int m_sizeWidth;
	int m_sizeHeight;
	static const std::string m_textureID;
	static const std::string m_ID;
};
#endif // !OPPONENT_H
