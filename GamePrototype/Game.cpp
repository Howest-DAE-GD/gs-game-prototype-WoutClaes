#include "pch.h"
#include "Game.h"
#include <iostream>

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
	for (int idx{}; idx <= 10; ++idx)
	m_EnemyPtrVctr.push_back(new Enemy(5, 80, 2));
}

void Game::Cleanup( )
{
}

void Game::Update( float elapsedSec )
{
	for (int idx{}; idx < m_EnemyPtrVctr.size(); ++idx)
	{
		m_EnemyPtrVctr[idx]->Update(elapsedSec);
	}

	
	for (int idx{}; idx < m_EnemyPtrVctr.size(); ++idx)
	{
		if (!m_EnemyPtrVctr[idx]->m_Alive)
		{
			if (!messagePrinted)
			{
				std::cout << "pick an upgrade (not in game yet)" << std::endl;
				messagePrinted = true;
			}
		}
		else
		{
			idx = m_EnemyPtrVctr.size();
		}
		// if (alive)
		// { break }
		// if (idx == size()-1) printmessage
	}
}

void Game::Draw( ) const
{
	ClearBackground();
	for (int idx{}; idx < m_EnemyPtrVctr.size(); ++idx)
	{
		m_EnemyPtrVctr[idx]->Draw();
	}
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	for (int idx{}; idx < m_EnemyPtrVctr.size(); ++idx)
	{
		m_EnemyPtrVctr[idx]->ProcessKeyDownEvent(e);
	}
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{	
	
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

