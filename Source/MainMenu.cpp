#include "MainMenu.hpp"

MainMenu::MainMenu( StateStack& stack, Context context )
	: State( stack, context )
	, m_options()
	, m_optionsIndex( 0 )
{
	std::cout << "MainMenu State Entered..." << std::endl;

	getContext().fonts -> loadResource( Font::Arcade, "Resources/Fonts/arcade.ttf" );

	sf::Text play;
	play.setFont( getContext().fonts -> getResource( Font::Arcade ) );
	play.setString( "Play" );
	play.setCharacterSize( 40 );
	play.setOrigin( play.getLocalBounds().width / 2, play.getLocalBounds().height / 2 );
	play.setPosition( getContext().window -> getView().getSize() / 2.0f );

	sf::Text options;
	options.setFont( getContext().fonts -> getResource( Font::Arcade ) );
	options.setString( "Options" );
	options.setCharacterSize( 40 );
	options.setOrigin( options.getLocalBounds().width / 2, options.getLocalBounds().height / 2 );
	options.setPosition( play.getPosition().x, play.getPosition().y + ( play.getCharacterSize() ) );

	sf::Text credits;
	credits.setFont( getContext().fonts -> getResource( Font::Arcade ) );
	credits.setString( "Credits" );
	credits.setCharacterSize( 40 );
	credits.setOrigin( credits.getLocalBounds().width / 2, credits.getLocalBounds().height / 2 );
	credits.setPosition( options.getPosition().x, options.getPosition().y + ( play.getCharacterSize() ) );

	sf::Text exit;
	exit.setFont( getContext().fonts -> getResource( Font::Arcade ) );
	exit.setString( "Exit" );
	exit.setCharacterSize( 40 );
	exit.setOrigin( exit.getLocalBounds().width / 2, exit.getLocalBounds().height / 2 );
	exit.setPosition( credits.getPosition().x, credits.getPosition().y + ( play.getCharacterSize() ) );

	m_options.push_back( play );
	m_options.push_back( options );
	m_options.push_back( credits );
	m_options.push_back( exit );

	updateOptions();
}

MainMenu::~MainMenu()
{
	getContext().fonts -> removeResource( Font::Arcade );

	std::cout << "MainMenu State Destroyed..." << std::endl;
}

void MainMenu::draw()
{
	for ( sf::Text& t : m_options )
	{
		getContext().window -> draw( t );
	}
}

bool MainMenu::update( sf::Time dt )
{
	return true;
}

bool MainMenu::handleEvent( const sf::Event& ev )
{
	if ( ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Return )
	{
		switch ( m_optionsIndex )
		{
		case Play:
			{
				requestStackPop();
				requestStackPush( States::Game );
			}
			break;

		case Options:
			{

			}

		case Credits:
			{

			}
			break;

		case Exit:
			{
				getContext().window -> close();
			}
			break;
		}
	}

	if ( ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Up )
	{
		if ( m_optionsIndex > 0 )
		{
			m_optionsIndex--;
		}

		else
		{
			m_optionsIndex = m_options.size() - 1;
		}

		updateOptions();
	}

	else if ( ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Down )
	{
		if ( m_optionsIndex < m_options.size() - 1 )
		{
			m_optionsIndex++;
		}

		else
		{
			m_optionsIndex = 0;
		}

		updateOptions();
	}

	return false;
}

void MainMenu::updateOptions()
{
	if ( m_options.empty() )
	{
		return;
	}

	for ( sf::Text& t : m_options )
	{
		t.setColor( sf::Color::White );
	}

	m_options[ m_optionsIndex ].setColor( sf::Color::Cyan );
}