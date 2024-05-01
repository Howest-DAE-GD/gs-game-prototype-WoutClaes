#pragma once
#include "utils.h"

class Player
{
public:

	Player(Point2f startPos);
	void Draw() const;
	void Update( float elapsedSec );
	Point2f GetPlayerPos();
	Circlef GetPlayerCircle();

private:
	enum class Direction
	{
		still, up, left, down, right
	};

	Point2f m_PlayerPos;
	Direction m_PlayerDirection;
};

