#pragma once
#include "Texture.h"
#include <iostream>
#include "utils.h"
class Bullet
{
public:
	Bullet(Point2f startpos, bool left, bool right, bool up, bool down);
	~Bullet();

	void Draw() const;
	void Update(float elapsedSec);
	Point2f GetBulletPos();

private:
	// functions

	// enum classes
	enum class BulletDirection
	{
		Up,
		Down,
		Left,
		Right
	};

	// datamembers
	const int m_BulletSpeed;
	BulletDirection m_BulletDirection;
	Point2f m_BulletPosition;
};

