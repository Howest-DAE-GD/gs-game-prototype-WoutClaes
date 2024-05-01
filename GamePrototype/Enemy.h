#pragma once
#include "utils.h"
#include "Bullet.h"
#include "Player.h"

class Enemy
{
public:
	Enemy(Point2f spawn, float health, float speed, float damage);
	void Draw() const;
	void Update(float elapsedsec, Point2f playerPos);
	Point2f GetEnemyPos();
	Circlef GetEnemyCircle();
	void ProcessKeyUpEvent(const SDL_KeyboardEvent& e);
	bool HitDetection();
	float m_Health;
private:

	Point2f m_Position;
	float m_Speed;
	float m_Damage;
	bool m_Alive;
	Player* m_Player;
	std::vector<Bullet*> m_BulletPtrVctr;
	float m_BulletDamage{ 1.f };
	float m_BulletSpeed{ 150.f };
};

