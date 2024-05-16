#pragma once
#include "utils.h"
#include "Bullet.h"
#include "Player.h"

class Enemy
{
public:
	Enemy(float health, float speed, float damage);
	void Draw() const;
	void Update(float elapsedsec);
	Point2f GetEnemyPos();
	Circlef GetEnemyCircle();
	void ProcessKeyDownEvent(const SDL_KeyboardEvent& e);
	bool HitDetectionBullet();
	bool HitDetectionPlayer();
	float m_Health;
	bool m_Alive;
private:

	Point2f m_Position;
	float m_Speed;
	float m_Damage;
	Player* m_Player;
	int m_BulletsMade{ 0 };
	float m_BulletDamage{ 1.f };
	float m_BulletSpeed{ 150.f };
	float m_BulletDelay;
};

