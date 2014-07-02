#include "State.hpp"
#include "StateStack.hpp"

State::State( StateStack& stack, Context context )
	: m_stack( &stack )
	, m_context( context )
{

}

State::Context::Context( sf::RenderWindow& window, TextureManager& textures, FontManager& fonts )
	: window( &window )
	, textures( &textures )
	, fonts( &fonts )
{

}

void State::requestStackPush( States::ID id )
{
	m_stack -> pushState( id );
}

void State::requestStackPop()
{
	m_stack -> popState();
}

void State::requestStackClear()
{
	m_stack -> clearStates();
}