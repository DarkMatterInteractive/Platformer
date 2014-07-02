#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <functional>
#include <string>
#include "State.hpp"
#include "Component.hpp"

namespace GUI
{
	class Button : public Component
	{
	public:

		typedef std::shared_ptr< Button > ButtonPtr;
		typedef std::function< void() >   Callback;

		Button( State::Context context );
		~Button();

		void setCallback( Callback callback );
		void setText( const std::string& text );
		void setCharacterSize( int size );
		void setToggle( bool flag );

		virtual bool isSelectable() const;
		virtual void select();
		virtual void deselect();

		virtual void activate();
		virtual void deactivate();

		virtual void handleEvent( const sf::Event& ev );

		int getCharacterSize() const { return m_text.getCharacterSize(); }

	private:

		virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;

		Callback   m_callback;
		sf::Sprite m_sprite;
		sf::Text   m_text;

		bool m_isToggle;
	};
};

#endif // BUTTON_HPP