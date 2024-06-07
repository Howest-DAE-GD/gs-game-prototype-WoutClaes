#include "pch.h"
#include "Player.h"
#include <iostream>
#include "Bullet.h"


int playerSize{ 15 };
Player::Player(Point2f startPos)
	:m_PlayerPos{startPos}
	,m_MovementSpeed{100}
	,m_BulletsDeleted{0}
	,m_BulletDelay{0}
	,m_Health{100}
{

}

void Player::Draw() const
{
	if (m_Health > 0)
	{
		utils::SetColor(Color4f{ 1.f,1.f,1.f,1.0f });
		utils::FillEllipse(m_PlayerPos, playerSize, playerSize);
	}
}

void Player::Update(float elapsedSec, bool hit)
{
	if (m_Health > 0)
	{
		// update the bullets
		if (m_BulletPtrVctr.size() > 0)
		{
			for (int idx{ m_BulletsDeleted }; idx < m_BulletPtrVctr.size(); ++idx)
			{
				m_BulletPtrVctr[idx]->Update(elapsedSec);

				if (hit)
				{
					delete m_BulletPtrVctr[m_BulletsDeleted];
					++m_BulletsDeleted;
				}
			}
		}

		if (m_BulletDelay >= 1)
		{
			m_BulletDelay += 1 * elapsedSec;

			if (m_BulletDelay > 1.5) m_BulletDelay = 0;
		}


		// Update the position

		const Uint8* pStates = SDL_GetKeyboardState(nullptr);

		// read the key values
		const bool isLeft{ bool(pStates[SDL_SCANCODE_A]) };
		const bool isRight{ bool(pStates[SDL_SCANCODE_D]) };
		const bool isUp{ bool(pStates[SDL_SCANCODE_W]) };
		const bool isDown{ bool(pStates[SDL_SCANCODE_S]) };

		//update position and sprite direction
		if (isLeft)
		{
			m_PlayerPos.x -= m_MovementSpeed * elapsedSec;
		}
		if (isRight)
		{
			m_PlayerPos.x += m_MovementSpeed * elapsedSec;
		}
		if (isUp)
		{
			m_PlayerPos.y += m_MovementSpeed * elapsedSec;
		}
		if (isDown)
		{
			m_PlayerPos.y -= m_MovementSpeed * elapsedSec;
		}
	}
}

void Player::ProcessKeyDownEvent(const SDL_KeyboardEvent& e)
{
	if (m_Health > 0)
	{
		switch (e.keysym.sym)
		{
		case SDLK_LEFT:
			// Bullet
			if (m_BulletDelay == 0)
			{
				m_BulletPtrVctr.push_back(new Bullet(m_PlayerPos, true, false, false, false));
				m_BulletDelay = 1;
			}
			break;
		case SDLK_RIGHT:
			//Bullet
			if (m_BulletDelay == 0)
			{
				m_BulletPtrVctr.push_back(new Bullet(m_PlayerPos, false, true, false, false));
				m_BulletDelay = 1;
			}
			break;
		case SDLK_UP:
			//Bullet
			if (m_BulletDelay == 0)
			{
				m_BulletPtrVctr.push_back(new Bullet(m_PlayerPos, false, false, true, false));
				m_BulletDelay = 1;
			}
			break;
		case SDLK_DOWN:
			//Bullet
			if (m_BulletDelay == 0)
			{
				m_BulletPtrVctr.push_back(new Bullet(m_PlayerPos, false, false, false, true));
				m_BulletDelay = 1;
			}
			break;
		}
	}
}

Point2f Player::GetPlayerPos()
{
	return m_PlayerPos;
}

Circlef Player::GetPlayerCircle()
{
	return Circlef(m_PlayerPos, playerSize);
}