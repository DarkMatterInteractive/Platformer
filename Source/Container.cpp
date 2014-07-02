#include "Container.hpp"
#include <iostream>

namespace GUI
{
	Container::Container()
		: m_children()
		, m_selectedChild( -1 )
	{

	}

	Container::~Container()
	{

	}

	void Container::pack( Component::CompPtr component )
	{
		m_children.push_back( component );

		if ( !hasSelection() && component -> isSelectable() )
		{
			select( m_children.size() - 1 );
		}
	}

	bool Container::isSelectable() const
	{
		return false;
	}

	void Container::handleEvent( const sf::Event& ev )
	{
		if ( hasSelection() && m_children[ m_selectedChild ] -> isActive() )
		{
			m_children[ m_selectedChild ] -> handleEvent( ev );
		}

		else if ( ev.type == sf::Event::KeyPressed )
		{
			if ( ev.key.code == sf::Keyboard::Up )
			{
				selectPrevious();
			}

			else if ( ev.key.code == sf::Keyboard::Down )
			{
				selectNext();
			}

			else if ( ev.key.code == sf::Keyboard::Return )
			{
				if ( hasSelection() )
				{
					m_children[ m_selectedChild ] -> activate();
				}
			}
		}
	}

	void Container::draw( sf::RenderTarget& target, sf::RenderStates states ) const
	{
		states.transform *= getTransform();

		for ( const Component::CompPtr& child : m_children )
		{
			target.draw( *child, states );
		}
	}

	bool Container::hasSelection() const
	{
		return m_selectedChild >= 0;
	}

	void Container::select( int index )
	{
		if ( m_children[ index ] -> isSelectable() )
		{
			if ( hasSelection() )
			{
				m_children[ m_selectedChild ] -> deselect();
			}

			m_children[ index ] -> select();
			m_selectedChild = index;
		}
	}

	void Container::selectNext()
	{
		if ( !hasSelection() )
		{
			return;
		}

		int next = m_selectedChild;

		do 
		{
			next = ( next + 1 ) % m_children.size();
		}
		while ( !m_children[ next ] -> isSelectable() );

		select( next );
	}

	void Container::selectPrevious()
	{
		if ( !hasSelection() )
		{
			return;
		}

		int prev = m_selectedChild;

		do
		{
			prev = ( prev + m_children.size() - 1 ) % m_children.size();
		}
		while ( !m_children[ prev ] -> isSelectable() );

		select( prev );
	}
};