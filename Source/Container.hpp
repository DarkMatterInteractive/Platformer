#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "Component.hpp"

namespace GUI
{
	class Container : public Component
	{
	public:

		typedef std::shared_ptr< Container > ContPtr;

		 Container();
		~Container();

		        void pack( Component::CompPtr component );

		virtual bool isSelectable() const;
		virtual void handleEvent( const sf::Event& ev );

	private:

		virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;

		        bool hasSelection() const;
		        void select( int index );
		        void selectNext();
		        void selectPrevious();

		std::vector< Component::CompPtr > m_children;
		int                               m_selectedChild;
	};
};

#endif // CONTAINER_HPP