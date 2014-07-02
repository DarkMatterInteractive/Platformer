#include "MainMenu.hpp"

MainMenu::MainMenu( StateStack& stack, Context context )
	: State( stack, context )
	, m_container()
{
	std::cout << "MainMenu State Entered..." << std::endl;

	getContext().fonts -> loadResource( Font::Arcade, "Resources/Fonts/arcade.ttf" );

	auto play = std::make_shared< GUI::Button >( getContext() );
	play -> setPosition( getContext().window -> getView().getSize() / 2.0f );
	play -> setText( "Play" );
	play -> setCharacterSize( 40 );
	play -> setCallback( [ this ] () 
	{
		requestStackPop();
		requestStackPush( States::Game );
	});

	auto options = std::make_shared< GUI::Button >( getContext() );
	options -> setPosition( play -> getPosition().x, play -> getPosition().y + play -> getCharacterSize() );
	options -> setText( "Options" );
	options -> setCharacterSize( 40 );

	auto credits = std::make_shared< GUI::Button >( getContext() );
	credits -> setPosition( options -> getPosition().x, options -> getPosition().y + options -> getCharacterSize() );
	credits -> setText( "Credits" );
	credits -> setCharacterSize( 40 );

	auto exit = std::make_shared< GUI::Button >( getContext() );
	exit -> setPosition( credits -> getPosition().x, credits -> getPosition().y + credits -> getCharacterSize() );
	exit -> setText( "Exit" );
	exit -> setCharacterSize( 40 );
	exit -> setCallback( [ this ] () 
	{
		requestStackClear();
		getContext().window -> close();
	});

	m_container.pack( play );
	m_container.pack( options );
	m_container.pack( credits );
	m_container.pack( exit );
}

MainMenu::~MainMenu()
{
	getContext().fonts -> removeResource( Font::Arcade );

	std::cout << "MainMenu State Destroyed..." << std::endl;
}

void MainMenu::draw()
{
	getContext().window -> draw( m_container );
}

bool MainMenu::update( sf::Time dt )
{
	return true;
}

bool MainMenu::handleEvent( const sf::Event& ev )
{
	m_container.handleEvent( ev );

	return false;
}