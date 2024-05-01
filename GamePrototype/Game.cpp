#include "pch.h"
#include "Game.h"

Game::Game( const Window& window ) 
	:BaseGame{ window }
{
	Initialize();
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize()
{
	m_Player = new Player(Point2f{300, 10});
	for (int idx{}; idx < m_Enemyamount; ++idx )
	m_EnemyPtrVctr.push_back(new Enemy(Point2f{float(rand() % 500) , float(rand() % 400)}, 10, 50, 1));
}

void Game::Cleanup( )
{
}

void Game::Update( float elapsedSec )
{
	m_Player->Update(elapsedSec);
	
	if (m_EnemyPtrVctr.size() > 0)
	{
		for (int idx{ }; idx < m_EnemyPtrVctr.size(); ++idx)
		{
			m_EnemyPtrVctr[idx]->Update(elapsedSec, m_Player->GetPlayerPos());
		}
	}
	for (int idx{ }; idx < m_EnemyPtrVctr.size(); ++idx)
		if (m_EnemyPtrVctr[idx]->HitDetection()) m_EnemyPtrVctr[idx]->m_Health - m_BulletDamage;
}

void Game::Draw( ) const
{
	ClearBackground( );
	m_Player->Draw();
	if (m_EnemyPtrVctr.size() > 0)
	{
		for (int idx{}; idx < m_EnemyPtrVctr.size(); ++idx) m_EnemyPtrVctr[idx]->Draw();
	}
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
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
	
	for (int idx{ }; idx < m_EnemyPtrVctr.size(); ++idx)
	{
		m_EnemyPtrVctr[idx]->ProcessKeyUpEvent(e);
	}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
	
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

