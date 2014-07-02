#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "State.hpp"
#include "Container.hpp"
#include "Button.hpp"

class MainMenu : public State
{
public:

	enum Options
	{
		Play,
		Options,
		Credits,
		Exit
	};

	         MainMenu( StateStack& stack, Context context );
	virtual ~MainMenu();

	virtual void draw();
	virtual bool update( sf::Time dt );
	virtual bool handleEvent( const sf::Event& ev );

private:

	GUI::Container m_container;
};

#endif // MAIN_MENU_HPP