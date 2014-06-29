#ifndef STATE_STACK_HPP
#define STATE_STACK_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <functional>
#include <assert.h>
#include "State.hpp"

class StateStack
{
public:

	enum Action
	{
		Push,
		Pop,
		Clear
	};

	StateStack( State::Context context );

	template < typename T >
	void registerState( States::ID id );

	void update( sf::Time dt );
	void draw();
	void handleEvent( const sf::Event& ev );

	void pushState( States::ID id );
	void popState();
	void clearStates();

	bool isEmpty() const { return m_stack.empty(); }

private:

	struct PendingChange
	{
		PendingChange( Action a );
		PendingChange( Action a, States::ID id );

		Action     action;
		States::ID id;
	};

	State::StatePtr createState( States::ID id );
	void            applyPendingChanges();
	
	std::vector< State::StatePtr >                             m_stack;
	std::vector< PendingChange >                               m_pendingList;
	State::Context                                             m_context;
	std::map< States::ID, State::StatePtr >                    m_factories;
	//std::map< States::ID, std::function< State::StatePtr() > > m_factories;
};

template < typename T >
void StateStack::registerState( States::ID id )
{
	State::StatePtr state( new T( *this, m_context ) );

	m_factories.insert( std::make_pair( id, std::move( state ) ) );

	//m_factories[ id ] = [ this ] () { return State::StatePtr( new T( *this, m_context ) ); };
}

#endif // STATE_STACK_HPP