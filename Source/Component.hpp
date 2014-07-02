#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <SFML/Graphics.hpp>
#include <memory>

namespace GUI
{
	class Component : public sf::Drawable, public sf::Transformable
	{
	public:

		typedef std::shared_ptr< Component > CompPtr;

		         Component();
		virtual ~Component();

		virtual bool isSelectable() const = 0;
		        bool isSelected() const;
		virtual void select();
		virtual void deselect();

		virtual bool isActive() const;
		virtual void activate();
		virtual void deactivate();

		virtual void handleEvent( const sf::Event& ev ) = 0;

	private:

		bool m_isSelected;
		bool m_isActive;
	};
};

#endif // COMPONENT_HPP