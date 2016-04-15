#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>

class Vector2
{
public:
	Vector2();
	Vector2(const float x, const float y);
	~Vector2();

	float length() { return sqrt(m_x * m_x + m_y * m_y); }

	float getX() { return m_x; }
	float getY() { return m_y; }

	void setX(const float x) { m_x = x; }
	void setY(const float y) { m_y = y; }

	//Vector2D operator+(const Vector2D& v2) const { return Vector2D(m_x + v2.m_x, m_y + v2.m_y); }
	Vector2 operator+(const Vector2& v2) const { return Vector2(m_x + v2.m_x, m_y + v2.m_y); }
	friend Vector2& operator +=(Vector2& v1, const Vector2& v2);
	friend Vector2& operator -=(Vector2& v1, const Vector2& v2);

	//void setX(const int x) { m_x = x; }
	//void setY(const int y) { m_y = y; }
	float m_x;
	float m_y;

private:

};
#endif // !VECTOR2_H
