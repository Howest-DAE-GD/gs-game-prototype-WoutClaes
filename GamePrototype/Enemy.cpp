#include "pch.h"
#include "Enemy.h"
#include <iostream>

int enemySize{ 30 };

Enemy::Enemy(float health, float speed, float damage)
	:m_Health{health}
	,m_Speed{speed}
	,m_Damage{damage}
	,m_Alive{true}
	,m_BulletDelay{ 0 }
{
	m_Player = new Player(Point2f{ 300, 10 });
	m_Position = Point2f{ float(rand() % 500),float(rand() % 300) };
}

void Enemy::Draw() const
{
	if (m_Alive)
	{
		utils::SetColor(Color4f{ 1,0,0,1 });
		utils::FillEllipse(m_Position.x, m_Position.y, enemySize, enemySize);
	}

	if (m_Player->m_BulletPtrVctr.size() > 0)
	{
		for (int idx{}; idx < m_Player->m_BulletPtrVctr.size(); ++idx) m_Player->m_BulletPtrVctr[idx]->Draw();
	}
	m_Player->Draw();
}

void Enemy::Update(float elapsedsec)
{
	m_Player->Update(elapsedsec, HitDetectionBullet());

	if (m_Alive)
	{
		Point2f temp = m_Player->GetPlayerPos() - m_Position;
		float angle = atan2(temp.y, temp.x);
		double multCos{ cos(angle) };
		double multSin{ sin(angle) };

		m_Position.x += (m_Speed * multCos) * elapsedsec;
		m_Position.y += (m_Speed * multSin) * elapsedsec;


		if (HitDetectionPlayer())
		{
			m_Player->m_Health -= 1 * elapsedsec;
		}
		if (HitDetectionBullet())
		{
			m_Health -= 1;
		}

		if (m_Health <= 0) m_Alive = false;
	}

	// update the bullets
	if (m_Player->m_BulletPtrVctr.size() > 0)
	{
		for (int idx{ }; idx < m_Player->m_BulletPtrVctr.size(); ++idx)
		{
			m_Player->m_BulletPtrVctr[idx]->Update(elapsedsec);
		}
	}

	if (m_BulletDelay >= 1)
	{
		m_BulletDelay += 1 * elapsedsec;

		if (m_BulletDelay > 1.5) m_BulletDelay = 0;
	}
}

Point2f Enemy::GetEnemyPos()
{
	return m_Position;
}

Circlef Enemy::GetEnemyCircle()
{
	return Circlef(m_Position, enemySize);
}

bool Enemy::HitDetectionBullet()
{
	bool isHit{};
	for (int idx{ }; idx < m_Player->m_BulletPtrVctr.size(); ++idx)
	{
		isHit = utils::IsPointInCircle(m_Player->m_BulletPtrVctr[idx]->GetBulletPos(), GetEnemyCircle());
	}
	return isHit;
}

bool Enemy::HitDetectionPlayer()
{
	bool isHit{};
	isHit = utils::IsOverlapping(m_Player->GetPlayerCircle(), GetEnemyCircle());
	return isHit;
}

void Enemy::ProcessKeyDownEvent(const SDL_KeyboardEvent& e)
{
	m_Player->ProcessKeyDownEvent(e);
}
