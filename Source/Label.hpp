#ifndef LABEL_HPP
#define LABEL_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "Component.hpp"
#include "ResourceManager.hpp"

namespace GUI
{
	class Label : public Component
	{
	public:

		typedef std::shared_ptr< Label > LabelPtr;

		Label( const std::string& text, const FontManager& fonts );

		virtual bool    isSelectable() const;
		        void    setText( const std::string& text );
		virtual void    handleEvent( const sf::Event& ev );

		const sf::Text& getText() const { return m_text; }

	private:

		virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;

		mutable sf::Text m_text;
	};
};

#endif // LABEL_HPP