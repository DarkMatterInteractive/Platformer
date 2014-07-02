#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <SFML/Graphics.hpp>
#include "StateStack.hpp"
#include "State.hpp"

class GameState : public State
{
public:

	         GameState( StateStack& stack, Context context );
	virtual ~GameState() { std::cout << "GameState Destroyed..." << std::endl; }

	virtual void draw();
	virtual bool update( sf::Time dt );
	virtual bool handleEvent( const sf::Event& ev );

private:

};

#endif // GAME_STATE_HPP