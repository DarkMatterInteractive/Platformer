#include "GameState.hpp"

GameState::GameState( StateStack& stack, Context context )
	: State( stack, context )
{
	std::cout << "GameState Entered..." << std::endl;
}

void GameState::draw()
{
	getContext().window -> draw( sf::RectangleShape( sf::Vector2f( 200, 200 ) ) );
}

bool GameState::update( sf::Time dt )
{
	return true;
}

bool GameState::handleEvent( const sf::Event& ev )
{
	if ( ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape )
	{
		requestStackPop();
		requestStackPush( States::MainMenu );
	}

	return false;
}