#include "pch.h"
#include "Player.h"

int playerSize{ 5 };

Player::Player(Point2f startPos)
	:m_PlayerPos{startPos}
	,m_PlayerDirection{Direction::still}
{
	//nothing else to do
}

void Player::Draw() const
{
	utils::SetColor(Color4f{ 1,1,1,1 });
	utils::FillEllipse(m_PlayerPos.x, m_PlayerPos.y, playerSize, playerSize);
}

void Player::Update(float elapsedSec)
{
	int Speed{ 100 };

	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	// read the key values
	const bool isLeft{ bool(pStates[SDL_SCANCODE_A]) };
	const bool isRight{ bool(pStates[SDL_SCANCODE_D]) };
	const bool isUp{ bool(pStates[SDL_SCANCODE_W]) };
	const bool isDown{ bool(pStates[SDL_SCANCODE_S]) };

	//update position
	if (isLeft)	m_PlayerPos.x -= Speed * elapsedSec;
	if (isRight)m_PlayerPos.x += Speed * elapsedSec;
	if (isUp)	m_PlayerPos.y += Speed * elapsedSec;
	if (isDown)	m_PlayerPos.y -= Speed * elapsedSec;

}

Point2f Player::GetPlayerPos()
{
	return m_PlayerPos;
}

Circlef Player::GetPlayerCircle()
{
	return Circlef(m_PlayerPos, playerSize);
}
