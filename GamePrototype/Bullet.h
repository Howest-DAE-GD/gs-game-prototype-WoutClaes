#pragma once
#include "utils.h"
class Bullet
{
public:
	Bullet(Point2f startpos, bool left, bool right, bool up, bool down, float damage, float speed);
	void Draw() const;
	void Update(float elapsedSec);
	Point2f GetBulletPos();

private:
	enum class Direction
	{
		up, left, down, right
	};

	Direction m_BulletDirection;
	float m_BulletSpeed;
	float m_Damage;
	Point2f m_Position;
	float m_Speed;
};

