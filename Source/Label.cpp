#include "Label.hpp"

namespace GUI
{
	Label::Label( const std::string& text, const FontManager& fonts )
		: m_text( text, fonts.getResource( Font::Arcade ), 40 )
	{
		setOrigin( m_text.getLocalBounds().width / 2, m_text.getLocalBounds().height / 2 );
	}

	bool Label::isSelectable() const
	{
		return false;
	}

	void Label::setText( const std::string& text )
	{
		m_text.setString( text );
		setOrigin( m_text.getLocalBounds().width / 2, m_text.getLocalBounds().height / 2 );
	}

	void Label::handleEvent( const sf::Event& ev )
	{

	}

	void Label::draw( sf::RenderTarget& target, sf::RenderStates states ) const
	{
		states.transform *= getTransform();

		target.draw( m_text, states );
	}
};