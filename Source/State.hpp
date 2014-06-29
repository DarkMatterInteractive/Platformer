#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "ResourceManager.hpp"

class StateStack;

namespace States
{
	enum ID
	{
		MainMenu,
		Options,
		Credits,
		Game,
		Paused,
		GameOver
	};
};

class State
{
public:

	typedef std::unique_ptr< State > StatePtr;

	struct Context
	{
		Context( sf::RenderWindow& window,
			     TextureManager&   textures,
				 FontManager&      fonts );

		sf::RenderWindow* window;
		TextureManager*   textures;
		FontManager*      fonts;
	};

	             State( StateStack& stack, Context context );
	virtual     ~State() {}

	virtual void draw() = 0;
	virtual bool update( sf::Time dt ) = 0;
	virtual bool handleEvent( const sf::Event& event ) = 0;

protected:

	void         requestStackPush( States::ID stateID );
	void         requestStackPop();
	void         requestStateClear();

	Context      getContext() const { return m_context; }

private:

	StateStack*  m_stack;
	Context      m_context;
};

#endif // STATE_HPP