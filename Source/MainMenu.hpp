#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "State.hpp"

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

	        void updateOptions();

private:

	std::vector< sf::Text > m_options;
	int                     m_optionsIndex;
};

#endif // MAIN_MENU_HPP