#include "Game.hpp"

Game::Game()
{
	std::ifstream windowConfig( "Config/WindowConfig.txt" );

	if ( !windowConfig.good() )
	{
		std::cout << "Could not find WindowConfig.txt..." << std::endl;
	}

	std::string title;
	int         width;
	int         height;

	windowConfig >> title;
	windowConfig >> width;
	windowConfig >> height;

	windowConfig.close();

	m_window.create( sf::VideoMode( width, height ), title );
}

void Game::run()
{
	while ( m_window.isOpen() )
	{
		while ( m_window.pollEvent( m_event ) )
		{
			if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) || m_event.type == sf::Event::Closed )
			{
				m_window.close();
			}
		}

		m_window.clear();
		m_window.display();
	}
}