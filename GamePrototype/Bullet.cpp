#include "pch.h"
#include "Bullet.h"

Bullet::Bullet(Point2f startpos, bool left, bool right, bool up, bool down)
	:m_BulletSpeed{150}
	,m_BulletPosition{startpos}
{
	if (left) m_BulletDirection = BulletDirection::Left;
	if (right) m_BulletDirection = BulletDirection::Right;
	if (up) m_BulletDirection = BulletDirection::Up;
	if (down) m_BulletDirection = BulletDirection::Down;
}

Bullet::~Bullet()
{
}

void Bullet::Draw() const
{
	const float bulletScale{ 15 };
	utils::SetColor(Color4f{ 0.f,1.f,0.f,1.0f });
	utils::DrawEllipse(m_BulletPosition, 5, 5);
}

void Bullet::Update(float elapsedSec)
{
	switch (m_BulletDirection)
	{
	case BulletDirection::Up:
		m_BulletPosition.y += m_BulletSpeed * elapsedSec;
		break;
	case BulletDirection::Down:
		m_BulletPosition.y -= m_BulletSpeed * elapsedSec;
		break;
	case BulletDirection::Left:
		m_BulletPosition.x -= m_BulletSpeed * elapsedSec;
		break;
	case BulletDirection::Right:
		m_BulletPosition.x += m_BulletSpeed * elapsedSec;
		break;
	}
}

Point2f Bullet::GetBulletPos()
{
	return m_BulletPosition;
}

