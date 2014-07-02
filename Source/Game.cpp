#include "Game.hpp"
#include "MainMenu.hpp"
#include "GameState.hpp"

Game::Game()
	: m_window()
	, m_event()
	, m_clock()
	, m_unprocessedTime( sf::Time::Zero )
	, m_textures()
	, m_fonts()
	, m_sounds()
	, m_states( State::Context( m_window, m_textures, m_fonts ) )
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

	loadResources();
	registerStates();

	m_states.pushState( States::MainMenu );
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
		m_states.draw();
		m_window.display();
	}
}

void Game::update( sf::Time dt )
{
	m_states.update( dt );
}

void Game::handleEvents()
{
	while ( m_window.pollEvent( m_event ) )
	{
		if ( m_event.type == sf::Event::Closed )
		{
			m_window.close();
		}

		m_states.handleEvent( m_event );
	}
}

void Game::loadResources()
{
	//m_fonts.loadResource( Font::Arcade, "Resources/Fonts/arcade.ttf" );
}

void Game::registerStates()
{
	m_states.registerState< MainMenu >( States::MainMenu );
	m_states.registerState< GameState >( States::Game );
}