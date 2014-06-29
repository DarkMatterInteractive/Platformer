#include "Game.hpp"

Game::Game()
	: m_window()
	, m_event()
	, m_clock()
	, m_unprocessedTime( sf::Time::Zero )
{
	std::ifstream windowConfig( "Config/WindowConfig.txt" );

	if ( !windowConfig.good() )
	{
		std::cout << "Could not find WindowConfig.txt..." << std::endl;
	}

	std::string title;
	int         width;
	int         height;

	// Load the window's configurations from the WindowConfig.txt file

	windowConfig >> title;
	windowConfig >> width;
	windowConfig >> height;

	windowConfig.close();

	m_window.create( sf::VideoMode( width, height ), title );
	m_window.setFramerateLimit( 60 );
}

void Game::run()
{
	while ( m_window.isOpen() )
	{
		sf::Time elapsed = m_clock.restart();

		m_unprocessedTime += elapsed;

		if ( m_unprocessedTime >= Util::TimePerFrame )
		{
			m_unprocessedTime -= Util::TimePerFrame;

			handleEvents();

			update( Util::TimePerFrame );
		}

		m_window.clear();
		m_window.display();
	}
}

void Game::update( sf::Time dt )
{
	
}

void Game::handleEvents()
{
	while ( m_window.pollEvent( m_event ) )
	{
		if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) || m_event.type == sf::Event::Closed )
		{
			m_window.close();
		}
	}
}