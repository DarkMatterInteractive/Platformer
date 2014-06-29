#include "Game.hpp"

Game::Game()
	: m_window()
	, m_event()
	, m_clock()
	, m_unprocessedTime()
	, m_currState( GameState::MainMenu )
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

	m_textures.loadResource( Texture::MainMenuScreen, "Resources/mainmenu.png" );
	m_textures.loadResource( Texture::PlayScreen, "Resources/play.png" );
	m_textures.loadResource( Texture::OptionsScreen, "Resources/options.png" );
	m_textures.loadResource( Texture::CreditsScreen, "Resources/credits.png" );

	m_states[ GameState::MainMenu ].reset( new SceneNode( m_textures.getResource( Texture::MainMenuScreen ) ) );
	m_states[ GameState::MainMenu ] -> setPosition( m_window.getSize().x / 2, m_window.getSize().y / 2 );

	m_states[ GameState::Playing ].reset( new SceneNode( m_textures.getResource( Texture::PlayScreen ) ) );
	m_states[ GameState::Playing ] -> setPosition( m_window.getSize().x / 2, m_window.getSize().y / 2 );

	m_states[ GameState::Options ].reset( new SceneNode( m_textures.getResource( Texture::OptionsScreen ) ) );
	m_states[ GameState::Options ] -> setPosition( m_window.getSize().x / 2, m_window.getSize().y / 2 );

	m_states[ GameState::Credits ].reset( new SceneNode( m_textures.getResource( Texture::CreditsScreen ) ) );
	m_states[ GameState::Credits ] -> setPosition( m_window.getSize().x / 2, m_window.getSize().y / 2 );
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
		m_window.draw( *m_states[ m_currState ] );
		m_window.display();
	}
}

void Game::update( sf::Time dt )
{
	switch ( m_currState )
		{
		case MainMenu:
			{
				if ( sf::Keyboard::isKeyPressed( sf::Keyboard::P ) )
				{
					m_currState = GameState::Playing;
				}

				if ( sf::Keyboard::isKeyPressed( sf::Keyboard::O ) )
				{
					m_currState = GameState::Options;
				}

				if ( sf::Keyboard::isKeyPressed( sf::Keyboard::C ) )
				{
					m_currState = GameState::Credits;
				}
			}
			break;

		case Playing:
			{
				if ( sf::Keyboard::isKeyPressed( sf::Keyboard::M ) )
				{
					m_currState = GameState::MainMenu;
				}
			}
			break;

		case Paused:
			{

			}
			break;

		case Options:
			{
				if ( sf::Keyboard::isKeyPressed( sf::Keyboard::M ) )
				{
					m_currState = GameState::MainMenu;
				}
			}
			break;

		case Credits:
			{
				if ( sf::Keyboard::isKeyPressed( sf::Keyboard::M ) )
				{
					m_currState = GameState::MainMenu;
				}
			}
			break;

		case GameOver:
			{

			}
			break;
		}
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