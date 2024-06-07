#pragma once
#include "Texture.h"
#include <vector>
class Bullet;

class Player
{
public:
	
	Player(Point2f startPos);
	void Draw() const;
	void Update(float elapsedSec, bool hit);
	void ProcessKeyDownEvent(const SDL_KeyboardEvent& e);
	Point2f GetPlayerPos();
	Circlef GetPlayerCircle();
	int m_Health;
	std::vector <Bullet* > m_BulletPtrVctr;
	int m_BulletsDeleted;

private:
	// enum classes
	enum class HeadRotation
	{
		down,
		left,
		right,
		up
	};
	enum class MovementDirection
	{
		Still,
		Up,
		Down,
		Left,
		Right,
	};
	
	// datamembers
	Point2f m_PlayerPos;
	const int m_MovementSpeed;
	float m_BulletDelay;
};

