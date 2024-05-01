#include "pch.h"
#include "Enemy.h"
#include <iostream>

int enemySize{ 10 };

Enemy::Enemy(Point2f spawn, float health, float speed, float damage)
	:m_Position{spawn}
	,m_Health{health}
	,m_Speed{speed}
	,m_Damage{damage}
	,m_Alive{true}
{
	m_Player = new Player(Point2f{ 300, 10 });
}

void Enemy::Draw() const
{
	if (m_Alive)
	{
		utils::SetColor(Color4f{ 1,0,0,1 });
		utils::FillEllipse(m_Position.x, m_Position.y, enemySize, enemySize);
	}

	if (m_BulletPtrVctr.size() > 0)
	{
		for (int idx{}; idx < m_BulletPtrVctr.size(); ++idx) m_BulletPtrVctr[idx]->Draw();
	}
}

void Enemy::Update(float elapsedsec, Point2f playerPos)
{
	m_Player->Update(elapsedsec);
	for (int idx{ }; idx < m_BulletPtrVctr.size(); ++idx)
	{
		m_BulletPtrVctr[idx]->Update(elapsedsec);
	}

	if (m_Alive)
	{
		Point2f temp = playerPos - m_Position;
		float angle = atan2(temp.y, temp.x);
		double multCos{ cos(angle) };
		double multSin{ sin(angle) };

		m_Position.x += (m_Speed * multCos) * elapsedsec;
		m_Position.y += (m_Speed * multSin) * elapsedsec;

		if (HitDetection()) m_Health -= 10;

		if (m_Health <= 0) m_Alive = false;
	}

	for (int idx{ }; idx < m_BulletPtrVctr.size(); ++idx)
	{
		m_BulletPtrVctr[idx]->Update(elapsedsec);
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

bool Enemy::HitDetection()
{
	bool isHit{};
	for (int idx{ }; idx < m_BulletPtrVctr.size(); ++idx)
	{
		isHit = utils::IsPointInCircle(m_BulletPtrVctr[idx]->GetBulletPos(), GetEnemyCircle());
		delete m_BulletPtrVctr[idx];
	}
	return isHit;
}

void Enemy::ProcessKeyUpEvent(const SDL_KeyboardEvent& e)
{
	switch (e.keysym.sym)
	{
	case SDLK_UP:
		m_BulletPtrVctr.push_back(new Bullet(m_Player->GetPlayerPos(), false, false, true, false, m_BulletDamage, m_BulletSpeed));
		break;
	case SDLK_LEFT:
		m_BulletPtrVctr.push_back(new Bullet(m_Player->GetPlayerPos(), true, false, false, false, m_BulletDamage, m_BulletSpeed));
		break;
	case SDLK_DOWN:
		m_BulletPtrVctr.push_back(new Bullet(m_Player->GetPlayerPos(), false, false, false, true, m_BulletDamage, m_BulletSpeed));
		break;
	case SDLK_RIGHT:
		m_BulletPtrVctr.push_back(new Bullet(m_Player->GetPlayerPos(), false, true, false, false, m_BulletDamage, m_BulletSpeed));
		break;
	}
}
