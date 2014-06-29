#include "StateStack.hpp"

StateStack::StateStack( State::Context context )
	: m_stack()
	, m_pendingList()
	, m_context( context )
	, m_factories()
{

}

StateStack::PendingChange::PendingChange( Action a, States::ID id )
	: action( a )
	, id( id )
{

}

StateStack::PendingChange::PendingChange( Action a )
	: action( a )
{

}

State::StatePtr StateStack::createState( States::ID id )
{
	auto found = m_factories.find( id );

	assert( found != m_factories.end() );

	return std::move( found -> second );

	//return found -> second();
}

void StateStack::update( sf::Time dt )
{
	for ( auto iter = m_stack.rbegin(); iter != m_stack.rend(); ++iter )
	{
		if ( !( *iter ) -> update( dt ) )
		{
			return;
		}
	}

	applyPendingChanges();
}

void StateStack::draw()
{
	for ( State::StatePtr& p : m_stack )
	{
		p -> draw();
	}
}

void StateStack::handleEvent( const sf::Event& ev )
{
	for ( auto iter = m_stack.rbegin(); iter != m_stack.rend(); ++iter )
	{
		if ( !( *iter ) -> handleEvent( ev ) )
		{
			return;
		}
	}

	applyPendingChanges();
}

void StateStack::applyPendingChanges()
{
	for ( PendingChange& p : m_pendingList )
	{
		switch ( p.action )
		{
		case Action::Push:
			{
				m_stack.push_back( createState( p.id ) );
			}
			break;

		case Action::Pop:
			{
				m_stack.pop_back();
			}

			break;

		case Action::Clear:
			{
				m_stack.clear();
			}
			break;
		}
	}

	m_pendingList.clear();
}

void StateStack::pushState( States::ID id )
{
	m_pendingList.push_back( PendingChange( Action::Push, id ) );
}

void StateStack::popState()
{
	m_pendingList.push_back( PendingChange( Action::Pop ) );
}

void StateStack::clearStates()
{
	m_pendingList.push_back( PendingChange( Action::Clear ) );
}