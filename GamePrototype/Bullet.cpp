#include "pch.h"
#include "Bullet.h"

Bullet::Bullet(Point2f startpos, bool left, bool right, bool up, bool down, float damage, float speed)
	:m_Position{startpos}
	,m_Damage{damage}
	,m_Speed{ speed }
{
	if (left) m_BulletDirection = Direction::left;
	if (right) m_BulletDirection = Direction::right;
	if (up) m_BulletDirection = Direction::up;
	if (down) m_BulletDirection = Direction::down;
}

void Bullet::Draw() const
{
	int size{ 2 };
	utils::SetColor(Color4f{ 0,1,0,1 });
	utils::FillEllipse(m_Position.x, m_Position.y, size, size);
}

void Bullet::Update(float elapsedSec)
{
	switch (m_BulletDirection)
	{
	case Bullet::Direction::up:
		m_Position.y += m_Speed * elapsedSec;
		break;
	case Bullet::Direction::left:
		m_Position.x -= m_Speed * elapsedSec;
		break;
	case Bullet::Direction::down:
		m_Position.y -= m_Speed * elapsedSec;
		break;
	case Bullet::Direction::right:
		m_Position.x += m_Speed * elapsedSec;
		break;
	}
}

Point2f Bullet::GetBulletPos()
{
	return m_Position;
}

