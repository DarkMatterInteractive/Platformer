#include "Button.hpp"

namespace GUI
{
	Button::Button( State::Context context )
		: m_callback()
		, m_sprite()
		, m_text( "", context.fonts -> getResource( Font::Arcade ) )
		, m_isToggle( false )
	{
		m_text.setOrigin( m_text.getLocalBounds().width / 2.0f, m_text.getLocalBounds().height / 2.0f );
	}

	Button::~Button()
	{

	}

	void Button::setCallback( Callback callback )
	{
		m_callback = std::move( callback );
	}

	void Button::setText( const std::string& text )
	{
		m_text.setString( text );
		m_text.setOrigin( m_text.getLocalBounds().width / 2.0f, m_text.getLocalBounds().height / 2.0f );
	}

	void Button::setCharacterSize( int size )
	{
		m_text.setCharacterSize( size );
	}

	void Button::setToggle( bool flag )
	{
		m_isToggle = flag;
	}

	bool Button::isSelectable() const
	{
		return true;
	}

	void Button::select()
	{
		Component::select();

		m_text.setColor( sf::Color::Cyan );
	}

	void Button::deselect()
	{
		Component::deselect();

		m_text.setColor( sf::Color::White );
	}

	void Button::activate()
	{
		Component::activate();

		if ( m_isToggle )
		{
			
		}

		if ( m_callback )
		{
			m_callback();
		}

		if ( !m_isToggle )
		{
			deactivate();
		}
	}

	void Button::deactivate()
	{
		Component::deactivate();

		if ( m_isToggle )
		{

		}
	}

	void Button::handleEvent( const sf::Event& ev )
	{

	}

	void Button::draw( sf::RenderTarget& target, sf::RenderStates states ) const
	{
		states.transform *= getTransform();

		target.draw( m_text, states );
	}
};